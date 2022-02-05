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
    ListNode* swapPairs(ListNode* head) {
        // dummy node
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        head = dummy;
        ListNode *prev = NULL, *next = NULL; 
        while (head->next && head->next->next) {
            prev = head->next;
            next = head->next->next;
            // head -> prev -> next
            // head -> next -> prev
            head->next = next;
            prev->next = next->next;
            next->next = prev;

            // advance
            head = prev;
        }
        return dummy->next;
    }
};
