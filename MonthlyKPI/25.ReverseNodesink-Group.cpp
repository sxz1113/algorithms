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
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (!(head && head->next)|| k == 1)
            return head;

        ListNode list_node = ListNode(0);
        ListNode *dummy = &list_node;
        dummy->next = head;

        ListNode *start = dummy;
        int i = 0;
        while (head) {
            ++i;
            if (i % k == 0) {
                start = reverse(start, head->next);
                head = start->next;
            } else {
                head = head->next;
            }
        }
        return dummy->next;
    }

private:
/**
 * @brief Resverse ListNode between start and stop, excluding start and stop
 * 
 * @param start 
 * @param stop 
 * @return * ListNode* 
 */
    ListNode* reverse(ListNode* start, ListNode* stop) {
        ListNode *prev = start,
                 *curr = start->next;
        ListNode *next = nullptr, 
                 *dummy = curr;

        while (curr != stop) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        start->next = prev;
        dummy->next = curr;
        return dummy;
    }
};