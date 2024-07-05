/*
 * @lc app=leetcode.cn id=49 lang=java
 *
 * [49] 字母异位词分组
 */

// @lc code=start

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.ArrayList;
import java.util.Arrays;

//! method1 sorting
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<String, List<String>>();
        for (int i = 0; i < strs.length; i++){
            char tempArray[] = strs[i].toCharArray();
            Arrays.sort(tempArray);
            String key = new String(tempArray);
            List<String> list = map.getOrDefault(key, new ArrayList<String>());
            list.add(strs[i]);
            map.put(key, list);
        }
        return new ArrayList<List<String>>(map.values());
    }
}
// @lc code=end

