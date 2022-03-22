#include "../Common.h"


class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), 
            res = n + 1;

        deque<long> dq;
        vector<long> prefix_sum(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
            if (i > 0)
                prefix_sum[i] += prefix_sum[i - 1];

            // if current prefix_sum[0, i] >= k, check if it's a candidate result
            if (prefix_sum[i] >= k) {
                res = min(res, i + 1);
            }

            // maintaining a monotonic increasing queue
            // analogue: 2 pointers
            // expansion to the right
            while (!dq.empty() && prefix_sum[i] - prefix_sum[dq.front()] >= k) {
                res = min(res, static_cast<int>(i - dq.front()));
                dq.pop_front();
            }

            // compression from the left
            while (!dq.empty() && prefix_sum[i] <= prefix_sum[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return res == (nums.size() + 1) ? -1 : res;
    }
};


class Solution {
public:
    // sort the prefix_sum array, 
    // then this problem => sliding window problem
    int shortestSubarray(vector<int>& nums, int k) {
        // create a min-heap priority queue for prefix_sum
        // smallest prefix_sum, highest priority
        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> pq;
        int res = nums.size() + 1;
        long sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];

            // if current prefix_sum[0, i] >= k, check if it's a candidate result
            if (sum >= k) {
                res = min(res, i + 1);
            }

            while (!pq.empty() && sum - pq.top().first >= k) {
                const pair<int, int>& p = pq.top();
                res = min(res, i - p.second);
                pq.pop();
            }
            
            pq.push({sum, i});
        }
        return res == (nums.size() + 1) ? -1 : res;
    }
};