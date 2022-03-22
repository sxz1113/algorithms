#include "../Common.h"


class Solution {
public:
    // tag: prefix sum, sliding window
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();

        long i = 0,
             sum = 0,
             res = 1;

        sort(nums.begin(), nums.end());
        /**
         * @brief compressible template

        // expansion
        for (long j = 0; j < n; ++j) {
            sum += nums[j];
            // compression,
            // if all numbers in the window nums[i: j] = nums[j] within k operations
            while ((j - i + 1) * nums[j] - sum > k)
                sum -= nums[i++];
            res = max(res, j - i + 1);
        }

        return res;
        */

        /**
         * @brief incompressible template
         */
        long j = 0;
        for (; j < n; ++j) {
            sum += nums[j];
            if ((j - i + 1) * nums[j] - sum > k)
                sum -= nums[i++];
        }

        return j - i;
    }
};