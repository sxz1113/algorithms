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
    // 以 i in 连续整数序列[left, right]为根节点， enumerate left subtrees and right subtrees：
    // 产生的以当前 i 为根结点的BST有left_nodes.size() * right_nodes.size()个
public:
    vector<TreeNode*> generateTrees(int n) {
        return n > 0 ? enumerate(1, n) : vector<TreeNode*>{};
    }

private:
    vector<TreeNode*> enumerate(int left, int right) {
        if (left > right)
            return vector<TreeNode*>{ nullptr };

        vector<TreeNode*> tree_nodes;
        for (int i = left; i <= right; ++i) {
            vector<TreeNode*> left_trees = enumerate(left, i - 1);
            vector<TreeNode*> right_trees = enumerate(i + 1, right);

            for (TreeNode* left_tree : left_trees) {
                for (TreeNode* right_tree : right_trees) {
                    TreeNode *tree_node = new TreeNode(i);
                    tree_node->left = left_tree;
                    tree_node->right = right_tree;
                    tree_nodes.push_back(tree_node);
                }
            }
        }
        return tree_nodes;
    };
};