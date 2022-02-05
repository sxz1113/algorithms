#include "../Common.h"


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head)
            return false;

        ListNode *slow = head, 
                 *fast = head->next;

        while (fast != slow) {
            // reach the end
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        return true;
    }
};