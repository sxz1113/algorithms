#include "Common.h"


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
private:
    unordered_map<Node*, Node*> m_ {};

public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;

        // copy head node
        Node *cur = head;

        // bsf with iter, copy node
        while (cur) {
            m_[cur] = new Node(cur->val);
            cur = cur->next;
        }

        // restart
        cur = head;

        // copy edges / pointers
        while (cur) {
            m_[cur] -> next = m_[cur->next];
            m_[cur] -> random = m_[cur->random];
            cur = cur->next;
        }

        return m_[head];
    }
};
