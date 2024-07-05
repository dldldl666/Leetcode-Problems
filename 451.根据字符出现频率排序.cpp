/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        string ans;
        unordered_map<char, int> table;
        for (auto c : s) {
            table[c]++;
        }
        vector<int> count;
        for (auto &item : table) {
            if (!contain(count, item.second)){
                count.emplace_back(item.second);
            }
        }
        sort(count.begin(), count.end());
        for (int i = count.size() - 1; i >= 0; i--) {
            for (auto &item : table) {
                if (item.second == count[i]){
                    for (int j = 0; j < count[i]; j++){
                        ans.push_back(item.first);
                    }
                }
            }
        }
        return ans;
    }
    bool contain (vector<int> count, int i) {
        for (int j = 0; j < count.size(); j++) {
            if (count[j] == i) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

