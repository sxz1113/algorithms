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
    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return 0;

        return dfs(root, targetSum) + 
            pathSum(root->left, targetSum) + 
            pathSum(root->right, targetSum);
    }

    // permutation
    int dfs(TreeNode* root, int sum) {
        if (!root)
            return 0;

        int cnt = root->val == sum ? 1 : 0;
        cnt += dfs(root->left, sum - root->val);
        cnt += dfs(root->right, sum - root->val);
        return cnt;
    }
};