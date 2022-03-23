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
    int goodNodes(TreeNode* root) {
        if (!root)
            return 0;

        return helper(root, root->val);
    }

    int helper(TreeNode* node, int max_val) {
        if (!node)
            return 0;

        int good_node = 0;
        if (node->val >= max_val) {
            max_val = node->val;
            good_node++;
        }

        return good_node + 
            helper(node->left, max_val) + 
            helper(node->right, max_val);
    }
};