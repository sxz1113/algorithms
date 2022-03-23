#include "../Common.h"


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        /**
         * @brief Tag: stack / queue / monotonic queue
         * DISCARD:
         *     1. discard any out of range element in front
         *        keep elements within [i - k, i] in the dequeue
         *     2. discard any element < nums[i] from back
         * Then dq will be monotonic increasing with respect to the sequence and value
         */
        int n = nums.size();
        vector<int> res;
        deque<int> dq;

        for (int i = 0; i < n; ++i) {
            // discard out of range element
            if (!dq.empty() && dq.front() == (i - k))
                dq.pop_front();

            // discard any element < nums[i]
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.push_back(i);

            if (i - k + 1 >= 0)
                res.push_back(nums[dq.front()]);
        }

        return res;
    }
};