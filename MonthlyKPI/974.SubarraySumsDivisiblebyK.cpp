#include "../Common.h"


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_mod;
        // account for the first subarray with a remainder that equals to zero.
        prefix_mod[0] = 1;
        int n = nums.size(),
            mod = 0,
            res = 0;

        for (int i = 0; i < n; ++i) {
            mod = (mod + nums[i] % k + k) % k;
            prefix_mod[mod] += 1;
            // increase by 过去的状态
            res += (prefix_mod[mod] - 1);
        }

        for (const auto& kv : prefix_mod) {
            printf("k = %d, v = %d\n", kv.first, kv.second);
        }

        return res;
    }
};
