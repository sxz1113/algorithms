#include "../Common.h"


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find the max(index of elbow point / peak)
        // if such point doesn't exist, return the reversed nums
        int n = nums.size();
        int i = n - 1;
        while (i > 0 && nums[i - 1] >= nums[i]) {
            i--;
        }

        int k = n - 1;
        for (int j = i; j < k; j++, k--)
            swap(nums[j], nums[k]);

        if (i > 0) {
            k = i--;
            while (nums[k] <= nums[i])
                k++;
            swap(nums[i], nums[k]);
        }
    }
};