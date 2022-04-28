#include "../Common.h"


class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        // 求最短的subarray，满足除以p的余数 == 整个数组的和除以p的余数。
        int n = nums.size();
        // 其实是prefix sum % p，因为会越界嗷嗷嗷
        unordered_map<int,int> prefix_sum;
        // k - prefix sum % p, v - idx
        prefix_sum[0] = -1;

        // causing overflow
        // int m = accumulate(nums.begin(), nums.end(), 0) % p;
        int m = 0;
        for (const int &num : nums)
            m = (m + num) % p;

        cout << "sum(nums) \% p = " << m << endl;
        if (m == 0)
            return 0;

        int res = n;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum = (sum + nums[i]) % p;
            int k = (sum - m + p) % p;
            if (prefix_sum.find(k) != prefix_sum.end()) {
                res = min(res, i - prefix_sum[k]);
            }
            prefix_sum[sum] = i;
        }

        return res == n ? -1 : res;
    }
};