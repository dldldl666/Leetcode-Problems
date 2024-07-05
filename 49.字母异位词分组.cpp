# include <vector>
# include <unordered_map>
# include <string>
# include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (auto str : strs){
            string key = str;
            sort(key.begin(), key.end());
            map[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = map.begin(); it != map.end(); it++){
            ans.emplace_back(it->second);
        }
        return ans;
    }
};