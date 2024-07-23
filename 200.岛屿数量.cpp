/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
//! THis is BFS solution
// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         queue <pair<int, int>> q;
//         int ans = 0;
//         int m = grid.size();
//         if (m == 0) return 0;
//         int n = grid[0].size();
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] == '1') {
//                     ans++;
//                     q.push({i, j});
//                     while (!q.empty()) {
//                         int x = q.front().first;
//                         int y = q.front().second;
//                         q.pop();
//                         if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1') {
//                             grid[x][y] = '0';
//                             if (x - 1 >= 0 && grid[x - 1][y] == '1') q.push({x - 1, y});
//                             if (x + 1 < m && grid[x + 1][y] == '1') q.push({x + 1, y});
//                             if (y - 1 >= 0 && grid[x][y - 1] == '1') q.push({x, y - 1});
//                             if (y + 1 < n && grid[x][y + 1] == '1') q.push({x, y + 1});
//                         }
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
    private:
    void dfs (vector<vector<char>>& grid, int x, int y) {
        //!这种方法叫做先污染后治理
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == '0') return;
        grid[x][y] = '0';
        dfs(grid, x - 1, y);
        dfs(grid, x + 1, y);
        dfs(grid, x, y - 1);
        dfs(grid, x, y + 1);
    }
    public:
        int numIslands(vector<vector<char>>& grid) {
            int ans = 0;
            int m = grid.size();
            if (m == 0) return 0;
            int n = grid[0].size();
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == '1') {
                        ans++;
                        dfs(grid, i, j);
                    }
                }
            }
            return ans;
        }
};
// @lc code=end

