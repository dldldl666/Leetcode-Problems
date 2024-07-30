/*
 * @lc app=leetcode.cn id=802 lang=cpp
 *
 * [802] 找到最终的安全状态
 */

// @lc code=start
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //! 要找所有终端节点和所有路径都通往终端节点的安全节点
        vector<int> endPoints;
        int n = graph.size();
        for (int i = 0; i < n; i++) {
            if (graph[i].empty()) {
                endPoints.push_back(i);
            }
        }
    }
};
// @lc code=end

