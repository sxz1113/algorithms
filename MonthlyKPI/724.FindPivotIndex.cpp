#include "../Common.h"


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix_sum(n + 1);
        for (int i = 1; i <= n; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1];
        }

        for (int i = 0; i < n; ++i) {
            if (prefix_sum[i] + prefix_sum[i + 1] == prefix_sum.back())
                return i;
        }

        return -1;
    }
};