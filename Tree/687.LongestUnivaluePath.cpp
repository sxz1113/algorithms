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
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return longest_path;
    }

private:
    // 全局变量
    int longest_path = 0;
    int dfs(TreeNode* node) {
        if (!node)
            return 0;

        // recursion
        int left_path = dfs(node->left);
        int right_path = dfs(node->right);

        // update longest path
        if (node->left && node->left->val == node->val)
            ++left_path;
        else
            left_path = 0;

        if (node->right && node->right->val == node->val)
            ++right_path;
        else
            right_path = 0;

        longest_path = max(longest_path, left_path + right_path);
        return max(left_path, right_path);
    }
};