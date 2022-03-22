#include "../Common.h"


class Solution {
public:
    // 2 pointers, sliding windows
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, 
            j = 0, 
            n = nums.size(), 
            res = n + 1;

        vector<int> prefix_sum(n + 1);
        for (int i = 1; i <= n; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1];
        }

        // while (i <= n && j <= n) {
        //     // expansion
        //     while (i < n && prefix_sum[i] - prefix_sum[j] < target) {
        //         ++i;
        //     }

        //     if (prefix_sum[i] - prefix_sum[j] >= target)
        //         res = min(res, i - j);

        //     // compression
        //     while (j < i && prefix_sum[i] - prefix_sum[j] >= target) {
        //         res = min(res, i - j);
        //         ++j;
        //     }

        //     ++i;
        // }

        for (int i = n; i >= 0 && prefix_sum[i] >= target; --i) {
            int j = upper_bound(prefix_sum.begin(), 
                                prefix_sum.end(), 
                                prefix_sum[i] - target) - prefix_sum.begin();
            res = min(res, i - j + 1);
        }
        return res == n + 1 ? 0 : res;
    }
};