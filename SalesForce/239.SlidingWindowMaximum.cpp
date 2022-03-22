#include "../Common.h"


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Idea: stack / queue
        // monotonic queue
        int n = nums.size();
        vector<int> res;
        deque<int> dq;

        for (int i = 0; i < k; ++i) {
            q.push_back(nums[i]);
            res.push_back(*max_element(q.begin(), q.end()));
        }

        for (int i = k; i < n; ++i) {
            q.pop_back();
            q.push_front(nums[i]);
            res.push_back(*max_element(q.begin(), q.end()));
        }

        return res;
    }
};