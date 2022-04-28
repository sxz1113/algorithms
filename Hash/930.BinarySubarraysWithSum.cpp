#include "../Common.h"


class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // hash and prefix sum
        int n = nums.size();
        int sum = 0, res = 0;
        int target;
        unordered_map<int, int> counter({{0, 1}});
        for (int num : nums) {
            sum += num;
            res += counter[sum - goal];
            ++counter[sum];
        }

        return res;
    }
};
