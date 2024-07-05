/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
 */

// @lc code=start


class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) {
            if (subRoot == nullptr){
                return true;
            }
            return false;
        }
        if (subRoot == nullptr){
            return false;
        }
        if (subRoot->val != root->val) {
            return isSubtree(root->left, subRoot) ||isSubtree(root->right, subRoot);
        }
        else {
            if (!isEqualTree(root, subRoot)) {
                return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
            }
            else {
                return true;
            }
        }
    }

    bool isEqualTree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) {
            if (subRoot == nullptr) {
                return true;
            }
            return false;
        }
        if (subRoot == nullptr) {
            return false;
        }
        if (root->val == subRoot->val) {
            return isEqualTree(root->left, subRoot->left) && isEqualTree(root->right, subRoot->right);
        }
        return false;
    }
};
// @lc code=end

