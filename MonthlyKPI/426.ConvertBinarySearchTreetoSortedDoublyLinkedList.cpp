#include "../Common.h"


/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};


class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        // in order traversal
        Node *prev = nullptr,
             *next = nullptr,
             *curr = root;

        if (!curr)
            return curr;

        dfs(root, prev, next);
        prev->right = next;
        next->left = prev;

        return next;
    }

private:
    void dfs(Node *node, Node *&prev, Node *&next) {
        if (node->left)
            dfs(node->left, prev, next);

        if (prev) {
            prev->right = node;
            node->left = prev;
        } else {
            next = node;
        }

        prev = node;
        if (node->right)
            dfs(node->right, prev, next);
    }
};
