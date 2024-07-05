/*
 * @lc app=leetcode.cn id=11 lang=java
 *
 * [11] 盛最多水的容器
 */

// @lc code=start

//! 能装多少水本质上是由两边中最短的那条边决定的
//! 所以用双指针，每次移动边较短的那个指针
//! 因为如果移动边较大的那个指针，可以证明面积只会减小
//! 每次移动完都相当于一个全新的数组
class Solution {
    public int maxArea(int[] height) {
        int maxA = 0;
        int i = 0;
        int j = height.length - 1;
        while (i < j) {
            if (height[i] <= height[j]){
                int area = (j - i) * height[i];
                if (area > maxA){
                    maxA = area;
                }
                i++;
            }
            else{
                int area = (j - i) * height[j];
                if (area > maxA){
                    maxA = area;
                }
                j--;
            }
        }
        return maxA;
    }
}
// @lc code=end

