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
    int findBottomLeftValueBFS(TreeNode* root) {
        // BFS
        queue<TreeNode* > q;
        q.push(root);

        while (!q.empty()) {
            root = q.front();
            q.pop();
            if (root->right)
                q.push(root->right);

            if (root->left)
                q.push(root->left);
            
        }

        return root->val;
    }

    int findBottomLeftValue(TreeNode* root) {
        // DFS
        int res = 0, h_max = 0;
        dfs(root, 1, h_max, res);
        return res;
    }

private:
    void dfs(TreeNode* root, int h_cur, int &h_max, int &res) {
        // stop condition, 到底了
        if (!root)
            return;

        // 第一个到下一层的，update res
        if (h_cur > h_max) {
            res = root->val;
            h_max = h_cur;
        }

        dfs(root->left, h_cur + 1, h_max, res);
        dfs(root->right, h_cur + 1, h_max, res);
    }
};
