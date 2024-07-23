/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     bool isBalanced(TreeNode* root) {
//         // 递归终止条件
//         if (root == nullptr) {
//             return true;
//         }
//         // 递归计算左右子树的高度
//         int left = height(root->left);
//         int right = height(root->right);
//         // 判断左右子树的高度差是否小于等于1
//         if (abs(left - right) > 1) {
//             return false;
//         }
//         // 递归判断左右子树是否为平衡二叉树
//         return isBalanced(root->left) && isBalanced(root->right);
//     }
//     int height (TreeNode* root) {
//         if (root == nullptr) {
//             return 0;
//         }
//         return max(height(root->left), height(root->right)) + 1;
//     }
// };//! 这个方法虽然对但时间复杂度太高

class Solution {
public:
    int height (TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        if (left == -1 || right == -1 || abs(left - right) > 1) {
            return -1;
        }
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return height(root) >= 0;
    }
};
// @lc code=end
