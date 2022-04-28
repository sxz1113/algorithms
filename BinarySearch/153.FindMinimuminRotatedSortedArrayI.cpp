#include "../Common.h"


class Solution {
public:
    int findMin(vector<int>& nums) {
        // l ... m ... r
        // isBlue = nums[m] > nums[0]

        int l = -1,
            n = nums.size(),
            r = nums.size(),
            m;

        while (l + 1 < r) {
            m = l + (r - l) / 2;
            if (nums[m] >= nums[0]) {
                l = m;
            } else {
                r = m;
            }
        }

        return nums[r % n];
    }
};