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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return res;
    }

private:
    unordered_map<string, int> counter;
    vector<TreeNode* > res;
    string dfs(TreeNode* root) {
        stringstream ss;
        if (!root)
            return "null";

        ss << root->val << "," << dfs(root->left) << "," << dfs(root->right);
        ++counter[ss.str()];
        if (counter[ss.str()] == 2)
            res.push_back(root);

        return ss.str();
    }
};