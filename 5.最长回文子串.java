class Solution {
    public String longestPalindrome(String s) {
        for (int i = s.length(); i > 0; i--){
            for (int j = 0; j < s.length() - i + 1; j++){
                String ss = s.substring(j, j + i);//PA 这里的substring是包含头不包含尾的
                if (isPalindrome(ss)){
                    return ss;
                }
            }
        }
        return s.substring(0,1);
    }
    public boolean isPalindrome(String s){
        StringBuffer buffer = new StringBuffer(s);
        String s1 = buffer.reverse().toString();
        if (s.equals(s1)) {
            return true;
        }
        return false;
    }
}//这个解法超时了

class Solution2 {
    public String longestPalindrome(String s) {
        int maxLeftIndex = 0;
        int maxRightIndex = 0;
        for (int i = 0; i < s.length(); i++){
            int left = i - 1;
            int right = i + 1;
            while (left >= 0 && right < s.length()){
                if (s.charAt(left) == s.charAt(right)){
                    left--;
                    right++;
                }
                else{
                    if (right - left - 2 + 1 > maxRightIndex - maxLeftIndex + 1){
                        maxLeftIndex = left + 1;
                        maxRightIndex = right - 1;
                    }
                    break;
                }
            }
            if (left == -1 || right == s.length()){
                if (right - left - 2 + 1 > maxRightIndex - maxLeftIndex + 1){
                    maxRightIndex = right - 1;
                    maxLeftIndex = left + 1;
                }
            }
        }
        if (maxLeftIndex == 0 && maxRightIndex == 0){
            for (int i = 0; i < s.length() - 1; i++){
                if (s.charAt(i) == s.charAt(i + 1)){
                    maxLeftIndex = i;
                    maxRightIndex = i + 1;
                }
            }
        }
        return s.substring(maxLeftIndex, maxRightIndex + 1);
    }
}//这是我的尝试，但是因为没考虑到aaaa这种情况导致不对

//标答1： 动态规划
// 只有 s[i + 1, j - 1] 是回文串 且s[i] 和 s[j] 相同时， s[i,j] 才是回文串
//! 同时还要注意边界条件，即子串的长度为1和2时
class Solution1right {
    public String longestPalindrome(String s) {
        int len = s.length();
        if (len < 2){
            return s;
        }

        int maxLen = 1;
        int begin = 0;
        //! This method is called dynamic programming? 动态规划
        //! dp[i][j] 表示 s[i,j] 是不是回文串
        boolean[][] dp = new boolean[len][len];
        //! Initialization: All the substring that has length 1 is 回文子串
        for (int i = 0; i < len; i++){
            dp[i][i] = true;
        }

        // 先递推子串长度
        // 再递推左边界，左边界的上限可以设置宽松一些
        for (int L = 2; L <= len; L++){
            for (int i = 0; i < len; i++){
                int j = L - i - 1;
                // If j is bigger than length, break;
                if (j >= len){
                    break;
                }

                if (s.charAt(i) != s.charAt(j)){
                    dp[i][j] = false;
                }
                else{
                    // 如果子串的长度是2，那么只要两个位置相等就是true
                    if (j - i < 3){
                        dp[i][j] = true;
                    }
                    //这就是动态规划的魅力所在，没必要用递归或者像我上面那个方法一样，用点空间存储起来也不错
                    else{
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if (dp[i][j] && j - i + 1 > maxLen){
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substring(begin, begin + maxLen);
    }
}