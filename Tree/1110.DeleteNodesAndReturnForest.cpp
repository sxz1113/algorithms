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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> roots;
        unordered_set<int> s(to_delete.begin(), to_delete.end());
        root = helper(root, roots, s);
        if (root)
            roots.push_back(root);

        return roots;
    }

private:
    TreeNode* helper(TreeNode* root, 
                    vector<TreeNode*>& roots,
                    unordered_set<int>& s) {
        // base case:
        if (!root) {
            return root;
        }

        root->left = helper(root->left, roots, s);
        root->right = helper(root->right, roots, s);

        if (s.find(root->val) != s.end()) {
            if (root->left)
                roots.push_back(root->left);

            if (root->right)
                roots.push_back(root->right);

            root = nullptr;
        }

        return root;
    }
};