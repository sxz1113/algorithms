#include "../Common.h"


/**
 * @brief Using Heap / Priority Queue
 * Keep it only having the kth-largest elements by popping off smaller elements
 * With only k elements, the smallest item will always be the kth largest.
 */
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        size_ = k;
        for (int i = 0; i < nums.size(); ++i) {
            pq_.push(nums[i]);
            if (pq_.size() > k)
                pq_.pop();
        }
    }

    int add(int val) {
        pq_.push(val);
        if (pq_.size() > size_)
            pq_.pop();

        return pq_.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> pq_;
    int size_ = 0;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
