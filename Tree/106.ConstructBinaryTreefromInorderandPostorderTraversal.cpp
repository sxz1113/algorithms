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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        if (n == 0)
            return nullptr;

        return helper(inorder, postorder, 0, n - 1, 0, n - 1);
    }

private:
    // recursion / divide and conquer
    TreeNode* helper(vector<int>& inorder,
                     vector<int>& postorder,
                     int i_start,
                     int i_end,
                     int p_start, 
                     int p_end) {
        if (i_start > i_end)
            return nullptr;

        TreeNode* root = new TreeNode(postorder[p_end]);
        auto iter = inorder.begin();
        int ptr = find(iter + i_start, iter + i_end, root->val) - iter;
        // cout << "break point = " << ptr << endl;

        int len_left = ptr - 1 - i_start;
        root->left = helper(inorder, postorder, i_start, ptr - 1, p_start, p_start + len_left);
        root->right = helper(inorder, postorder, ptr + 1, i_end, p_start + len_left + 1, p_end - 1);
        return root;
    }
};