#include "../Common.h"


class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        assert(parent.size() == s.size());
        n = s.size();

        // 根据parents, reconstruct tree
        for (int i = 0; i < n; ++i)
            graph[parent[i]].push_back(i);

//         for (const auto [k, v]: graph) {
//             cout << k << ": ";
//             for (const int& i : v)
//                 cout << i << ", ";

//             cout << endl;
//         }

        // 设计dfs函数，with recursion
        dfs(0, s);
        return res + 1;
    }

private:
    // 用map代表tree: key - parent idx, val - child idx
    unordered_map<int, vector<int>> graph;
    int res = 0;
    // 多少个tree nodes
    int n = 0;
    /**
     * @brief dfs(node id) -> 通过current node的longest path
     * @param node node id
     * @return * int 
     */
    int dfs(int i, const string &s) {
        int max_len = 0;

        // 如果有child node且value != parent node.value
        // 失误：不是binary tree！！！遍历所有child node然后排序最大的1 / 2条子path
        // ref: https://leetcode-cn.com/problems/longest-path-with-different-adjacent-characters/solution/by-endlesscheng-92fw/
        // maxLen 表示遍历过的父、子间的最长路径，len 表示当前这一条路径长度，遍历一遍后，可以覆盖所有情况；最终找到父到最长的两个子的路径长度和
        vector<int> len_children;
        for (const int j : graph[i]) {
            // 不管等不等于，要recursion
            int len = dfs(j, s) + 1;
            // cout << "len = " << len << endl;
            if (s[i] != s[j]) {
                res = max(res, max_len + len);
                max_len = max(max_len, len);
            }
        }
        return max_len;
    }
};