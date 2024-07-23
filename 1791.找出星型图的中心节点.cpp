/*
 * @lc app=leetcode.cn id=1791 lang=cpp
 *
 * [1791] 找出星型图的中心节点
 */

// @lc code=start
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> arr(edges.size() + 1,0);
        for (auto p : edges) {
            arr[p[0]]++;
            arr[p[1]]++;
        }
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == edges.size() - 1) {
                return i;
            }
        }
        return 0;
    }
};
// @lc code=end

