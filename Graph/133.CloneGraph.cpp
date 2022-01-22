#include "Common.h"


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


// BFS
class Solution {
private:
    queue<Node*> q_;
    unordered_map<Node*, Node*> m_;

public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return NULL;

        // clone head node in the original graph
        Node *head = new Node(node->val);
        q_.push(node);
        m_[node] = head;

        // clone nodes
        while (!q_.empty()) {
            Node *cur = q_.front();
            q_.pop();

            for (Node *n : cur->neighbors) {
                // if not visited, enqueue
                if (m_.find(n) == m_.end()) {
                    q_.push(n);
                    m_[n] = new Node(n->val);
                }
                // if visited, clone edges
                m_[cur]->neighbors.push_back(m_[n]);
            }
        }

        return head;
    }
};