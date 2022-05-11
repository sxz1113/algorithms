#include "../Common.h"


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if (!dfs(root, voyage)) {
            res.clear();
            res.push_back(-1);
        }

        return res;
    }

private:
    // 当前访问的点
    int ptr = 0;
    vector<int> res;
    bool dfs(TreeNode *node, vector<int> &voyage) {
        if (!node)
            return true;

        if (node->val != voyage[ptr])
            return false;

        ++ptr;
        // recursion
        if (dfs(node->left, voyage) && dfs(node->right, voyage))
            return true;

        if (dfs(node->right, voyage) && dfs(node->left, voyage)) {
            res.push_back(node->val);
            return true;
        }

        return false;
    }
};
