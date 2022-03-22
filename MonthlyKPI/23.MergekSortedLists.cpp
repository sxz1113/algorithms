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
    // Brute force
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = nullptr;
        for (ListNode *list : lists) {
            head = merge(head, list);
        }

        return head;
    }

    // 2 pointers
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size(),
            rhs = n - 1;
        int lhs;
        
        if (n == 0)
            return nullptr;
        
        while (rhs > 0) {
            // reset lhs
            lhs = 0;
            while (lhs < rhs) {
                lists[lhs] = merge(lists[lhs], lists[rhs]);
                lhs++;
                rhs--;
            }
        }

        return lists[0];
    }

private:
    ListNode* merge(ListNode *lhs, ListNode *rhs) {
        // if lhs is empty, append the rest of rhs
        if (!lhs)
            return rhs;

        // if rhs is empty, append the rest of lhs
        if (!rhs)
            return lhs;

        ListNode *head;
        // advance lhs if its current value is smaller, and vice versa
        if (lhs->val < rhs->val) {
            head = lhs;
            head->next = merge(lhs->next, rhs);
        } else {
            head = rhs;
            head->next = merge(lhs, rhs->next);
        }
        return head;
    }
};

// Priority queue
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = nullptr;

        // define a less comparator for min heap to sort ListNodes
        auto cmp = [](ListNode *lhs, ListNode *rhs) {
            return lhs->val > rhs->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq {cmp};

        for (ListNode *list : lists) {
            if (list) {
                pq.push(list);
            }
        }

        ListNode *dummy = new ListNode();
        ListNode *cur = dummy;
        while (!pq.empty()) {
            ListNode *node = pq.top();
            pq.pop();
            cur->next = node;
            cur = cur->next;
            if (cur->next) {
                pq.push(cur->next);
            }
        }

        return dummy->next;
    }

};