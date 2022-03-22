#include "../Common.h"


class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if (nums.size() == 3)
            return nums[0] * nums[1] * nums[2];

        sort(nums.begin(), nums.end());
        int n = nums.size();
        // check largest 3 numbers against 2 negative numbers * largest number
        return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[0] * nums[1] * nums[n - 1]);
    }
};