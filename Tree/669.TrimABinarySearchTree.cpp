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
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        setBounds(low, high);
        return helper(root);
    }

private:
    int lo_;
    int hi_;
    void setBounds(int low, int high) {
        lo_ = low;
        hi_ = high;
    }
    TreeNode* helper(TreeNode* root) {
        if (!root)
            return nullptr;

        if (root->val < lo_)
            return helper(root->right);

        if (root->val > hi_)
            return helper(root->left);

        root->left = helper(root->left);
        root->right = helper(root->right);
        return root;
    }
};
