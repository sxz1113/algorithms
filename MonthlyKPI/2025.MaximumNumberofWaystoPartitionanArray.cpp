#include "../Common.h"


class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        long sum_total = accumulate(nums.begin(), nums.end(), 0L);
        long sum_cur = 0;
        int n = nums.size(), pivot;
        unordered_map<long, int> check_sum_left, check_sum_right;

        // 1. no changing
        for (long i = 0; i < nums.size() - 1; ++i) {
            sum_cur += nums[i];
            check_sum_right[sum_cur*2 - sum_total]++;
        }

        // 2. with changing
        pivot = check_sum_right[0];
        sum_cur = 0;
        for (long i = 0; i < nums.size(); ++i) {
            sum_cur += nums[i];
            long d = k - nums[i], k = sum_cur*2 - sum_total;
            pivot = max(pivot, check_sum_left[d] + check_sum_right[-d]);
            check_sum_right[k]--;
            check_sum_left[k]++;
        }

        return pivot;
    }
};