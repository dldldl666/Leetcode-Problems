/*
 * @lc app=leetcode.cn id=1334 lang=cpp
 *
 * [1334] 阈值距离内邻居最少的城市
 */

// @lc code=start
//! 这个和743是同一个类型，都是 shortest path problem
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int inf = INT_MAX / 2;
        vector<vector<int>> g(n, vector<int>(n, inf));
        for (auto &e : edges) {
            g[e[0]][e[1]] = g[e[1]][e[0]] = e[2];
        }
        vector<int> numberOfCity(n,0);
        //! 遍历所有的节点作为source，存储最短路径
        for (int i = 0; i < n; i++) {
            vector<int> dist(n, inf);
            dist[i] = 0;
            vector<int> used(n, 0);
            for (int j = 0; j < n; j++) {
                int x = -1;
                for (int y = 0; y < n; y++) {
                    if (!used[y] && (x == -1 || dist[y] < dist[x])) {
                        x = y;
                    }
                }
                used[x] = true;
                for (int y = 0; y < n; y++) {
                    dist[y] = min(dist[y], dist[x] + g[x][y]);
                }
            }
            for (int j = 0; j < n; j++) {
                if (dist[j] <= distanceThreshold) {
                    numberOfCity[j] ++;
                }
            }
        }
        int minimumCity = 0;
        int minimumNumber = numberOfCity[0];
        for (int i = 0; i < n; i++) {
            if (numberOfCity[i] <= minimumNumber) {
                minimumCity = i;
                minimumNumber = numberOfCity[i];
            }
        }
        return minimumCity;
    }
};
// @lc code=end

