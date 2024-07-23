/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (auto c: word) {
            if (node->children[c - 'a'] == nullptr) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (auto c : word) {
            // if (node->isEnd == true) {
            //     return true;
            // }
            if (node->children[c - 'a'] == nullptr) {
                return false;
            }
            node = node->children[c - 'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (auto c : prefix) {
            if (node->children[c - 'a'] == nullptr) {
                return false;
            }
            node = node->children[c - 'a'];
        }
        return true;
    }
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;
        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    TrieNode* root;
    //! 这一道题目的关键就是这个TrieNode的实现过程
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

