/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;

    void dfs(int u) {
        visited[u] = 1; //! 搜索过程中，设为1
        for (int v : edges[u]) {
            if (visited[v] == 0) {//! 未搜索，设为0
                dfs(v);
                if (!valid) {
                    return;
                }
            }
            else if (visited[v] == 1) {//! 又遇到搜索中，说明出现了循环，没有topological sort
                valid = false;
                return;
            }
        }
        visited[u] = 2;//! 搜索完，设为2，如再遇到啥也不做
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //! 感觉就是不能有循环
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
        }
        for (int i = 0; i < numCourses && valid; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        return valid;
    }
};
// @lc code=end

