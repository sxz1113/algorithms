#include "../Common.h"


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, mod;
        unordered_map<int, int> prefix_mod;

        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            mod = sum % k;
            if (mod == 0 && i >= 1) {
                return true;
            }

            if (prefix_mod.empty() || prefix_mod.find(mod) == prefix_mod.end()) {
                prefix_mod[mod] = i;
            } else if (i - prefix_mod[mod] >= 2) {
                return true;
            }
        }
        return false;
    }
};