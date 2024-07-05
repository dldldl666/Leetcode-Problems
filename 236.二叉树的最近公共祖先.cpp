/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
# include <unordered_map>
using namespace std;
class Solution {
public:
    TreeNode* ans;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return false;
        }
        bool leftSon = dfs(root->left, p, q);
        bool rightSon = dfs(root->right, p, q);
        // 这个就是作为lowestCommonAncestor 的条件
        if ((leftSon && rightSon) ||((root->val == p->val || root->val == q->val) && (leftSon || rightSon))){
            ans = root;
        }
        return leftSon || rightSon ||(root->val == p->val || root->val == q->val);
        // leftSon 是左边有没有找到包含p或q的，rightson是右边有没有包含，这个return值真的非常巧妙
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs (root, p, q);
        return ans;
    }
};

class Solution {
public:
    unordered_map<int, TreeNode*> fa;
    unordered_map<int, bool> vis;
    void dfs (TreeNode* root) {
        if (root->left != nullptr) {
            fa [root->left->val] = root;
            dfs(root->left);
        }
        if (root->right != nullptr) {
            fa [root->right->val] = root;
            dfs(root->right);
        }
    }

    TreeNode* lowestCommonAncestor (TreeNode* root, TreeNode* p, TreeNode* q) {
        fa[root->val] = nullptr;
        dfs(root);
        while (p != nullptr) {
            vis[p->val] = true;
            p = fa[p->val];
        }
        while (q != nullptr) {
            if (vis[q->val]) {
                return q;
            }
            q = fa[q->val];
        }
    }
};//! 这个有哈希表存储父节点的方法也很骚，学！
// @lc code=end

