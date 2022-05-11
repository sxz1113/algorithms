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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        // 提前遍历整棵树做预处理，记录整棵树最深的深度maxDepth，以及总共有多少个深度是maxDepth的节点.
        queue<TreeNode* > q;
        TreeNode *cur = root;
        q.push(cur);
        int depth = 0;

        while (!q.empty()) {
            int n = q.size();
            cout << "depth = " << depth << ":";
            leaves.clear();
            for (int i = 0; i < n; ++i) {
                cur = q.front();
                q.pop();
                leaves.push_back(cur);
                cout << " " << cur->val;
                if (cur->left)
                    q.push(cur->left);

                if (cur->right)
                    q.push(cur->right);
            }
            ++depth;
            cout << endl;
        }

        dfs(root);
        // 然后第二次遍历整棵树，从下往上查看每个节点包含多少个maxDepth的叶子节点。
        // 当找到第一个数目是deepCount的节点时，说明它的子树下面包含了所有的deepest leaves，这就是答案。
        return lcaNode;
    }

private:
    vector<TreeNode* > leaves;
    TreeNode* lcaNode = nullptr;
    int dfs(TreeNode *node) {
        if (!node)
            return 0;

        int res = 0;
        for (const TreeNode *leaf : leaves) {
            res += (node->val == leaf->val);
        }

        res += dfs(node->left) + dfs(node->right);
        if (res == leaves.size()) {
            lcaNode = node;
            res = -1;
        }
        return res;
    }
};