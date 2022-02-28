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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // edge case
        if (preorder.empty())
            return nullptr;

        int idx_root = 0;
        return helper(preorder, inorder, idx_root, 0, preorder.size() - 1);
    }

private:
    TreeNode* helper(vector<int>& preorder,
                     vector<int>& inorder,
                     int& idx_root,
                     int idx_start,
                     int idx_end) {
        if (idx_root >= preorder.size() || idx_start > idx_end)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[idx_root]);
        int ptr = find(inorder.begin() + idx_start, 
                       inorder.begin() + idx_end,
                       root->val) - inorder.begin();
        idx_root++;
        root->left = helper(preorder, inorder, idx_root, idx_start, ptr - 1);
        root->right = helper(preorder, inorder, idx_root, ptr + 1, idx_end);
        return root;
    }
};