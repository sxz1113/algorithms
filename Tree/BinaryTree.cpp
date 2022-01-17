#include <algorithm>
#include <cstddef>
#include <locale>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <stack>


using namespace std;

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

class Solution144 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // recursion
        // vector<int> res {};
        // traverse_(root, res);
        // return res;

        vector<int> preorder {};
        if (!root) {
            return preorder;
        }

        stack<TreeNode*> stack;
        stack.push(root);
        TreeNode* node;

        while (!stack.empty()) {
            node = stack.top();
            stack.pop();

            preorder.push_back(node->val);
            if (node->right) {
                stack.push(node->right);
            }

            if (node->left) {
                stack.push(node->left);
            }

        }

        return preorder;
    }

private:
    void traverse_(TreeNode* root, vector<int>& res) {
        if (!root) {
            return;
        }
        
        cout << "res: " << endl;
        for_each(res.begin(), res.end(), [](int i) {
            cout << i << ", ";
        });

        res.push_back(root->val);
        traverse_(root->left, res);
        traverse_(root->right, res);
    }
};


class Solution110 {
public:
    bool isBalanced(TreeNode* root) {
        return (maxDepth_(root) != -1);
    }

private:
    int maxDepth_(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int l = maxDepth_(root->left);
        int r = maxDepth_(root->right);

        if (l == -1 || r == -1 || abs(l - r) > 1) {
            return -1;
        }

        return max(l, r) + 1;
    }
};


class Solution98 {
public:
    TreeNode *MinNode = nullptr;
    TreeNode *MaxNode = nullptr;

    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }

        if (MinNode && root->val <= MinNode->val) {
            return false;
        }

        if (MaxNode && root->val >= MaxNode->val) {
            return false;
        }

        MaxNode = root;
        bool l = isValidBST(root->left);

        MinNode = root;
        bool r = isValidBST(root->right);

        return l && r;
    }
};


class BSTIterator {
private:
    stack<TreeNode*> stack_ {};
    TreeNode *cur_node;

    void push_all(TreeNode *node) {
        for (; node != nullptr; stack_.push(node), node = node->left);
    }

public:
    BSTIterator(TreeNode* root) {
        push_all(root);
    }
    
    int next() {
        while (cur_node != nullptr) {
            stack_.push(cur_node);
            cur_node = cur_node->left;
        }

        int res = stack_.top()->val;
        stack_.pop();
        push_all(cur_node->right);

        return res;
    }
    
    bool hasNext() {
        return !stack_.empty();
    }
};

int main(int argc, char* argv[]) {
    // vector<vector<int>> test {{1, 1}};
    // int solution = Solution144().preorderTraversal(test, 0);
    // cout << solution << endl;
}
