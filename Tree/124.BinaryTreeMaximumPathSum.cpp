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
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return max_sum;
    }

private:
    // 全局变量记录最大值
    int max_sum = INT_MIN;

    // 自底向上递归
    int maxGain(TreeNode* node) {
        if (!node)
            return 0;

        // recursion
        int left_gain = max(maxGain(node->left), 0);
        int right_gain = max(maxGain(node->right), 0);

        // update max sum
        max_sum = max(max_sum, left_gain + node->val + right_gain);

        // return max contribution from this node
        return node->val + max(left_gain, right_gain);
    }
};
