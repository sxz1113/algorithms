#include "../Common.h"


class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    // Node* connect(Node* root) {
    //     // 1. BFS
    //     if (!root)
    //         return nullptr;

    //     queue<Node* > q;
    //     q.push(root);˜
    //     while(!q.empty()) {
    //         int n = q.size();
    //         Node *prev = nullptr;
    //         for (int i = 0; i < n; ++i) {
    //             Node *node = q.front();
    //             q.pop();
    //             if (node->left)
    //                 q.push(node->left);

    //             if (node->right)
    //                 q.push(node->right);

    //             if (prev)
    //                 prev->next = node;

    //             prev = node;
    //         }
    //     }
    //     return root;
    // }

    Node* connect(Node* root) {
        if (!root)
            return nullptr;

        // 位于第 x 层时为第 x + 1 层建立 next 指针
        Node *curr = root,
             *prev = nullptr,
             *next = nullptr;

        while (curr) {
            Node* p = curr;
            while (p) {
                if (p->left)
                    traverse(prev, p->left, next);

                if (p->right)
                    traverse(prev, p->right, next);

                p = p->next;
            }
            curr = next;
        }
    }

    void traverse(Node* &prev, Node* &p, Node* &next) {
        if (prev)
            prev->next = p;

        if (!next)
            next = p;

        next = p;
    }
};