/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
private:
    int dfs(vector<vector<int>>& grid, int x, int y, int area) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) {
            return 0;
        }
        grid[x][y] = 0;
        area++;
        return area + dfs(grid, x + 1, y, 0) + dfs(grid, x - 1, y, 0) + dfs(grid, x, y + 1, 0) + dfs(grid, x, y - 1, 0);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int res = dfs(grid, i, j, 0);
                    if (res > ans) {
                        ans = res;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

