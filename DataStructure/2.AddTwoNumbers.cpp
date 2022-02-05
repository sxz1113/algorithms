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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode *l3 = &head;

        int carry_over = 0, sum = 0, x, y;
        while (l1 || l2 || carry_over) {
            x = (l1 == nullptr) ? 0 : l1->val;
            y = (l2 == nullptr) ? 0 : l2->val;
            sum = x + y + carry_over;
            carry_over = sum / 10;
            printf("node = %d, carry over = %d\n", 
                l3->val,
                carry_over);

            l3->next = new ListNode(sum % 10);
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
            l3 = l3->next;
        }

        return head.next;
    }
};