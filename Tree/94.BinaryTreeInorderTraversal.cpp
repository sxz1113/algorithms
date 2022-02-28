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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;

        // recursive version
        // dfs(root, res);
        // return res;

        stack<TreeNode* > stk;
        TreeNode* head = root;
        while (head || !stk.empty()) {
            while (head) {
                stk.push(head);
                head = head->left;
            }
            head = stk.top();
            stk.pop();
            res.push_back(head->val);
            head = head->right;
        }

        return res;
    }

// recursive version
private:
    void dfs(TreeNode* root, vector<int>& arr) {
        if (!root)
            return;

        dfs(root->left, arr);
        arr.push_back(root->val);
        dfs(root->right, arr);
    }
};
