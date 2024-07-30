/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
//! similar to 1584
//! use disjoint set to solve this problem
class DisjointSetUnion {
    private:
        vector<int> f, rank;
        int n;
    public:
        DisjointSetUnion (int _n) {
            n = _n;
            f.resize(n);
            rank.resize(n, 1);
            for (int i = 0; i < n; i++) {
                f[i] = i;
            }
        }

        int find (int x) {
            return f[x] == x ? x : find(f[x]);
        }

        int unionSet(int x, int y) {
            int fx = find(x);
            int fy = find(y);
            if (fx == fy) {
                return false; //! already connected
            }
            if (rank[fx] < rank[fy]) {
                swap(fx, fy); //! let fx be the bigger rank one
            }
            rank[fx] += rank[fy];
            f[fy] = fx;
            return true;
        }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //! 如果删掉这条边还能遍历所有的元素，那么这条边就是多余边
        DisjointSetUnion dsu(edges.size()); // since the vertices of the tree is number of edges - 1, here is one extra edge
        vector<vector<int>> extra;
        for (auto& e : edges) {
            if (dsu.find(e[0] - 1) == dsu.find(e[1] - 1)) {
                extra.push_back(e);
            }
            else {
                dsu.unionSet(e[0] - 1, e[1] - 1);
            }
        }
        return extra.back();
    }
};
// @lc code=end

