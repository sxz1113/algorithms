#include "../Common.h"


/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int d_ = 0;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return d_;
    }
    int dfs(TreeNode* root) {
        if (!root)
            return 0;

        int l = dfs(root->left), r = dfs(root->right);
        // update depth
        d_ = max(d_, l + r);
        return 1 + max(l, r);
    }
};