/*
 * @lc app=leetcode.cn id=38 lang=java
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
    public String countAndSay(int n) {
        if (n == 1){
            return "1";
        }
        return RLE(countAndSay(n - 1));
    }

    public String RLE(String s){
        int count = 0;
        String ans = new String();
        char valueNow = s.charAt(0);
        for (int i = 0; i < s.length(); i++){
            if (s.charAt(i) == valueNow){
                count++;
            }
            else {
                ans += Character.forDigit(count, 10);
                ans += valueNow;
                valueNow = s.charAt(i);
                count = 1;
            }
        }
        ans += Character.forDigit(count, 10);
        ans += valueNow;
        return ans;
    }
}//! 改进： 可以将每个值存在hash表中就不用recursion了！
// @lc code=end

