#include "../Common.h"


class Solution {
public:
// tag: sliding window
// find the longest subarray containing at most k zeros
    int longestOnes(vector<int>& nums, int k) {
        int res = 0;
        for (int i = 0, j = 0; j < nums.size(); ++j) {
            if (nums[j] == 0)
                --k;

            if (k < 0 && nums[i++] == 0)
                ++k;

            res = max(res, j - i + 1);
        }

        return res;
    }
};