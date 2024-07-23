/*
 * @lc app=leetcode.cn id=1926 lang=cpp
 *
 * [1926] 迷宫中离入口最近的出口
 */

// @lc code=start
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        //! 广度优先搜索
        int m = maze.size();
        int n = maze[0].size();
        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};//顺序是右上左下
        queue<tuple<int, int, int>> q;
        q.emplace(entrance[0],entrance[1], 0);
        //! 将入口设为墙
        maze[entrance[0]][entrance[1]] = '+';
        while (!q.empty()) {
            auto [cx, cy, d] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nx = cx + dx[k];
                int ny = cy + dy[k];
            if (nx >= 0 && nx < m && ny >=0 && ny < n && maze[nx][ny] == '.') {
                if (nx == 0 || nx == m - 1 || ny == 0 || ny == n - 1) {
                    return d + 1;
                }
                //! 下面这步的目的是防止走回头路
                maze[nx][ny] = '+';
                q.emplace(nx, ny, d + 1);
            }
            }
        }
    return -1;
    }
};
// @lc code=end

