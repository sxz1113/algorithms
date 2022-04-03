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
    void flatten(TreeNode* root) {
        // pre-order traversal
        if (root)
            return traverse(root);
    }

private:
    TreeNode* head = nullptr;
    void traverse(TreeNode* node) {
        if (node->right)
            traverse(node->right);

        if (node->left)
            traverse(node->left);

        node->left = nullptr;
        node->right = head;
        head = node;
    }
};