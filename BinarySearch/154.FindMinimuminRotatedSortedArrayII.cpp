#include "../Common.h"


class Solution {
public:
    int findMin(vector<int>& nums) {
        // l ... m ... r
        // isBlue = nums[m] > nums[r]

        int l = 0,
            r = nums.size() - 1,
            m;

        while (l < r) {
            m = l + (r - l) / 2;
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else if (nums[m] < nums[r]){
                r = m;
            } else {
                --r;
            }
        }

        return nums[r];
    }
};