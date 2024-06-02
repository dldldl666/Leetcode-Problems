/*
 * @lc app=leetcode.cn id=3 lang=java
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start

import java.util.HashSet;
import java.util.Hashtable;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int result = 0;
        for (int i = 0; i < s.length(); i++){
            HashSet<Character> hashSet = new HashSet<>();
            for (int j = i; j < s.length(); j++){
                if (!hashSet.contains(s.charAt(j))){
                    hashSet.add(s.charAt(j));
                }
                else{
                    result = Math.max(result, j - i);
                    break;
                }
                result = Math.max (result, j -i + 1);// 因为第j位属于这个子串（如果不重复）
            }
        }
        return result;
    }
}
// @lc code=end

