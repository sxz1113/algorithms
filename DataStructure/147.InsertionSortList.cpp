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
    ListNode* insertionSortList(ListNode* head) {
        // insertion sort
        ListNode pre = ListNode(0);
        ListNode *dummy = &pre;
        dummy->next = head;
        ListNode *cur = head;

        while (head) {
            cur = dummy->next;
            while (cur) {
                if (cur == head)
                    break;

                if (cur->val > head->val)
                    swap(cur->val, head->val);

                cur = cur->next;
            }
            head = head->next;
        }
        return dummy->next;
    }
};