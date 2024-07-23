/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue <Node*> q;
        if (!root) return root;
        q.push(root);
        int i = 0;
        int j = 0;
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            j++;
            if (j == pow(2, i)) {
                node->next = NULL;
                i++;
                j = 0;
            } else {
                node->next = q.front();
            }
            if (node->left) {
                q.push(node->left);
                q.push(node->right);
            }
        }
        return root;
    }
};
// @lc code=end

