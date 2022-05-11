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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // ref: https://leetcode-cn.com/problems/delete-node-in-a-bst/solution/miao-dong-jiu-wan-shi-liao-by-terry2020-tc0o/
        if (!root) {
            return nullptr;
        }

        if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {
            if (!root->left)
                return root->right;

            if (!root->right)
                return root->left;

            // 替换大于这个root的节点（在右边）
            TreeNode *tree_node = root->right;
            // 右子树的最小值是右子树最左下角的节点
            // 搜索仅次于root的tree_node
            while (tree_node->left)
                tree_node = tree_node->left;

            tree_node->left = root->left;
            root = root->right;
        }
        return root;
    }
};