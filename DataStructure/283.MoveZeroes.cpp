#include "../Common.h"


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n_zeros = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                n_zeros++;
                continue;
            } else {
                nums[i - n_zeros] = nums[i];
            }
        }

        while (n_zeros > 0) {
            nums[n - n_zeros] = 0;
            n_zeros--;
        }
    }
};