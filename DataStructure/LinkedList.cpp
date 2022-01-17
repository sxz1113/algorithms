#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <type_traits>
#include <unordered_map>
#include <vector>
#include <stack>
#include <limits>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


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


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution82 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy_head = new ListNode(0, head);
        ListNode* duplicate_node;
        int val;

        head = dummy_head;
        while (head->next && head->next->next) {
            if (head->next->val == head->next->next->val) {
                val = head->next->val;
                while (head->next && head->next->val == val) {
                    duplicate_node = head->next;
                    head->next = head->next->next;
                    delete duplicate_node;
                }
            }

            else {
                head = head->next;
            }
        }

        return dummy_head->next;
    }
};


class Solution83 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;

        while (cur && cur->next) {
            if (cur->val == cur->next->val) {
                ListNode* duplicateNode = cur->next;
                cur->next = cur->next->next;
                delete duplicateNode;
            } else {
                cur = cur->next;
            }
        }

        return head;
    }
};


class Solution206 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *next = nullptr;

        while (head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }
};


class Solution92 {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // validate params, check corner cases
        if (left >= right || !head) {
            return head;
        }

        // add dummy head to the linked list
        ListNode *dummy = new ListNode(0), *pre = dummy, *cur, *post;
        dummy->next = head;

        // advance to the left
        for (int i = 1; i < left; ++i) {
            if (!pre) {
                return nullptr;
            }

            pre = pre->next;
        }

        // do reverse for the next nodes until hitting right
        cur = pre->next;

        for (int i = left; i < right; ++i) {
            if (!cur) {
                return nullptr;
            }

            post = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = post;
        } 

        return dummy->next;
    }
};


class Solution86 {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) {
            return nullptr;
        }

        ListNode *leftdummy = new ListNode(0), 
                 *rightdummy = new ListNode(0);

        ListNode *left = leftdummy, *right = rightdummy;

        while (head) {
            if (head->val < x) {
                left = left->next = head;
            } else {
                right = right->next = head;
            }

            head = head->next;
        }

        right->next = nullptr;
        left->next = rightdummy->next;
        return leftdummy->next;
    }
};


class Solution148 {
private:
    /**
     * @brief Use fast-slow pointer to find the median of a linked list
     * 
     * @param head 
     * @return ListNode* 
     */
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* lhs, ListNode* rhs) {
        ListNode pre = ListNode(0);
        ListNode* cur = &pre;

        while (lhs && rhs) {   
            if (lhs->val < rhs->val) {
                cur->next = lhs;
                lhs = lhs->next;
            } else {
                cur->next = rhs;
                rhs = rhs->next;
            }
            cur = cur->next;
        }
        if (lhs != nullptr)
            cur->next = lhs;
        else
            cur->next = rhs;

        return pre.next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* m = findMiddle(head);
        ListNode* r = sortList(m->next);
        m->next = nullptr;
        ListNode* l = sortList(head);
        return merge(l, r);
    }
};


class Solution143 {
private:
    ListNode* findMiddle(ListNode* head) {
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head) {
        ListNode *newHead = nullptr, *tmp = nullptr;
        while (head) {
            tmp = head->next;
            head->next = newHead;
            newHead = head;
            head = tmp;
        }
        return newHead;
    }

    void merge(ListNode* lhs, ListNode* rhs) {
        int i = 0;
        ListNode pre = ListNode(0);
        ListNode* cur = &pre;

        while (lhs && rhs) {   
            if (i % 2 == 0) {
                cur->next = lhs;
                lhs = lhs->next;
            } else {
                cur->next = rhs;
                rhs = rhs->next;
            }
            cur = cur->next;
            i++;
        }
        if (lhs != nullptr)
            cur->next = lhs;
        else
            cur->next = rhs;
    }

public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        ListNode* mid = findMiddle(head);
        ListNode* tail = reverse(mid->next);
        mid->next = nullptr;
        merge(head, tail);
    }
};


class Solution141 {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }

        ListNode *slow = head, 
                 *fast = head->next;

        // while (fast && fast->next) {
        //     slow = slow->next;
        //     fast = fast->next->next;
        //     if (slow == fast) {
        //         return true;
        //     }
        // }
        // return false;
        while (fast != slow) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        return true;
    }
};


class Solution142 {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode *slow = head,
                 *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};


class Solution23 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        auto cmp = [](ListNode *lhs, ListNode *rhs)->bool {
            return lhs->val > rhs->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> heap {cmp};
        for (ListNode* list : lists) {
            if (list) {
                heap.push(list);
            }
        }

        ListNode pre = ListNode(0);
        ListNode *cur = &pre;
        while (!heap.empty()) {
            ListNode *head = heap.top();
            heap.pop();
            cur->next = head;
            cur = cur->next;
            if (head->next) {
                heap.push(head->next);
            }
        }
        return pre.next;
    }
};


class Solution138 {
public:
    Node* copyRandomList(Node* head) {
        return head;
    }
};


class Solution108 {
private:
    TreeNode* buildBST(vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int mid = (start + end) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = buildBST(nums, start, mid - 1);
        node->right = buildBST(nums, mid + 1, end);
        return node;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }
        return buildBST(nums, 0, nums.size() - 1);
    }
};


class Solution109 {
private:
    ListNode* cur;
    int getSize(ListNode* head) {
        int size = 0;
        while (head) {
            size++;
            head = head->next;
        }

        return size;
    }

    TreeNode* helper(int size) {
        if (size == 0) {
            return nullptr;
        }

        TreeNode* left = helper(size / 2);
        TreeNode* root = new TreeNode(cur->val);
        cur = cur->next;
        TreeNode* right = helper(size - 1 - size / 2);
        root->left = left;
        root->right = right;
        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        
        if (!head->next) {
            return new TreeNode(head->val);
        }

        ListNode *slow = head,
                 *fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* mid = slow->next;
        slow->next = nullptr;
        
        TreeNode* root = new TreeNode(mid->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        return root;
    }
};

int main(int argc, char* argv[]) {
    ;
}
