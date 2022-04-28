#include "../Common.h"


class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size(),
            res = 0;

        for (int i = 0; i < n - 1; ++i) {
            // check condition 2
            if ((i - res) % 2 == 0 && nums[i] == nums[i + 1])
                res++;
        }
        
//         check if the length of nums is even
        return res + (n - res) % 2;
    }
};