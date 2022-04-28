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
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;

        // 右子树的最小值是右子树最左下角的节点
        // 左子树的最大值是左子树最右下角的节点
        // TreeNode* tree_node;
        // if (root->left) {
        //     tree_node = root->left;
        //     // go go 去最右边
        //     while (tree_node->right)
        //         tree_node = tree_node->right;
        //         if (tree_node->val >= root->val)
        //             return false;
        // }

        // if (root->right) {
        //     tree_node = root->right;
        //     // go go 去最左边
        //     while (tree_node->left) {
        //         tree_node = tree_node->left;
        //         if (tree_node->val <= root->val)
        //             return false;
        //     }
        // }

        // return isValidBST(root->left) && isValidBST(root->right);
        return valid(root, LONG_MIN, LONG_MAX);
    }
private:
    bool valid(TreeNode *root, long min, long max) {
        if (!root)
            return false;

        if (root->val <= min || root->val >= max)
            return false;

        return valid(root->left, min, root->val) && valid(root->right, root->val, max);
    }
};
