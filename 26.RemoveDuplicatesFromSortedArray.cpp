#include "Common.h"


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int duplicates = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1])
                duplicates++;
            else
                nums[i - duplicates] = nums[i];
        }

        return nums.size() - duplicates;
    }
};