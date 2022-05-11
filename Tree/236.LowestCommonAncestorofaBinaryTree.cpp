#include "../Common.h"


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lcaNode = nullptr;
        stack<TreeNode*> stk;
        TreeNode* node = root;
        int count = 0;

        while (node || !stk.empty()) {
            if (node) {
                stk.push(node);
                node = node->left;
            } else {
                node = stk.top();
                stk.pop();
                if (node->val == p->val || node->val == q->val)
                    ++count;
                if (count == 2) {
                    lcaNode = node;
                    break;
                }
                node = node->right;
            }
        }
        return lcaNode;
    }
};