#include "../Common.h"


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        stack<pair<int, int>> stk;
        stk.push({-1, 0});

        ListNode *cur = head;
        while (cur) {
            while (stk.empty())
            {
                /* code */
            }
            
        }
        
    }
};