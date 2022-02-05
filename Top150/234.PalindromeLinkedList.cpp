#include "Common.h"


/**
 * Definition for singly-linked list.
 */
// fast and slow pointer 快慢指针
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;

        ListNode *fast, *slow;
        slow = head;
        fast = head->next;

        // while fast reach the end, slow reach the middle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse
        ListNode *pre = NULL, *next = NULL;
        while (slow) {
            next = slow->next;
            slow->next = pre;
            pre = slow;
            slow = next;
        }

        // compare
        while (pre) {
            printf("comparing %d - %d\n", head->val, pre->val);
            if (head->val != pre->val)
                return false;

            head = head->next;
            pre = pre->next;
        }

        return true;
    }
};
