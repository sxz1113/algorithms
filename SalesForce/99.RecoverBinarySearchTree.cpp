#include "../Common.h"


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) :  val(x), left(left), right(right) {}
};


class Solution {
public:
    void recoverTree(TreeNode* root) {
        traverse(root);
        if (left && right)
            swap(left->val, right->val);
    }

private:
    TreeNode *prev = nullptr,
             *left = nullptr,
             *right = nullptr;
 
    // in order traversal -> nodes in increasing order
    void traverse(TreeNode* root) {
        if (!root)
            return;

        traverse(root->left);
        if (prev && prev->val > root->val) {
            if (!left)
                left = prev;

            right = root;
        }

        prev = root;
        traverse(root->right);
    } 
};