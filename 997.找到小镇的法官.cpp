/*
 * @lc app=leetcode.cn id=997 lang=cpp
 *
 * [997] 找到小镇的法官
 */

// @lc code=start
// class Solution {
// public://!方法一，计算各节点的入度和出度
//     int findJudge(int n, vector<vector<int>>& trust) {
//         vector<int> in(n + 1,0);
//         vector<int> out(n + 1,0);
//         for (auto p : trust) {
//             out[p[0]]++;
//             in[p[1]]++;
//         }
//         for (int i = 1; i < n + 1; i++) {
//             if (in[i] == n - 1 && out[i] == 0){
//                 return i;
//             }
//         }
//         return -1;
//     }
// };

class Solution {
public://!方法二，只用一个数组就够了
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> arr(n + 1,0);
        for (auto p : trust) {
            arr[p[0]]--;
            arr[p[1]]++;
        }
        for (int i = 1; i < n + 1; i++) {
            if (arr[i] == n - 1){
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

