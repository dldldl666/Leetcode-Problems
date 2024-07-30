/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 *
 * [1584] 连接所有点的最小费用
 */

// @lc code=start

class DisjointSetUnion {
private:
    vector<int> f, rank;
    int n;
public:
    DisjointSetUnion(int _n) {
        n = _n;
        rank.resize(n, 1);
        f.resize(n);
        for (int i = 0; i < n; i++) {
            f[i] = i;
        }
    }

    int find (int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    int unionSet(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) {
            return false;
        }
        if (rank[fx] < rank[fy]) {
            swap(fx, fy);
        }
        rank[fx] += rank[fy];
        f[fy] = fx;
        return true;
    }
};

struct Edge {
    int len, x, y;
    Edge(int len, int x, int y) : len(len), x(x), y(y){}
};
//! Above is the Kruskal method


class Solution {

// public:
//     int minCostConnectPoints(vector<vector<int>>& points) {
//         auto dist = [&] (int x, int y) -> int {
//             return abs(points[x][0] - points[y][0]) + abs(points[x][1] - points[y][1]);
//         };
//         int n = points.size();
//         DisjointSetUnion dsu(n);
//         vector<Edge> edges;
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 edges.emplace_back(dist(i,j), i, j);
//             }
//         }
//         sort(edges.begin(), edges.end(), [](Edge a, Edge b) -> int {return a.len < b.len;});
//         int res = 0, num = 1;
//         for (auto& [len, x, y] : edges) {
//             if (dsu.unionSet(x, y)) {
//                 res += len;
//                 num++;
//                 if (num == n) {
//                     break;
//                 }
//             }
//         }
//         return res;
//     }

//! Below is the prim method
public:
    int prim(vector<vector<int>>& points, int start) {
        int n = points.size();
        int res = 0;

        // 1. construct matrix of distance
        vector<vector<int>> g(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                g[i][j] = g[j][i] = dist;
            }
        }
        // 2. record the distance of nodes in V to the shortest graph
        vector<int> lowcost(n, INT_MAX);
        // 3. record if nodes in V has been add to the shortest graph
        vector<int> v(n);

        // 4. add start to shortest graph
        v[start] = 1;
        for (int i = 0; i < n; i++) {
            if (i == start) {
                continue;
            }
            lowcost[i] = g[i][start];
        }

        // 5. traverse all nodes that haven't been add to shortest spanning tree
        for (int i = 1; i < n; i++) {
            int minIdx = -1;
            int minVal = INT_MAX;
            //! 找出此时V中离shortest graph最近的点
            for (int j = 0; j < n; j++) {
                if (v[j] == 0 && lowcost[j] < minVal) {
                    minIdx = j;
                    minVal = lowcost[j];
                }
            }
            v[minIdx] = 1;
            res += minVal;
            //! 更新lowcost
            for (int j = 0; j < n; j++) {
                if (v[j] == 0 && g[j][minIdx] < lowcost[j]) {
                    lowcost[j] = g[j][minIdx];
                }
            }
        }
        return res;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        return prim(points, 0);
    }
};

//!也试试prim能不能做
// @lc code=end

