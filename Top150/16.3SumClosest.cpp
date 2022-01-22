#include "Common.h"


// 2 pointers
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // edge case
        if (nums.size() < 3)
            return 0;

        // order by asc
        sort(nums.begin(), nums.end());
        int sum_closest, sum, delta = INT_MAX;
        for (int k = 0; k < nums.size() - 2; ++k) {
            if (k > 0 && nums[k] == nums[k - 1])
                continue;

            int i = k + 1,
                j = nums.size() - 1;

            while (i < j) {
                sum = nums[i] + nums[j] + nums[k];
                // printf("nums(%d, %d, %d), sum = %d, sum_closest = %d",
                //     i, k, j, sum, sum_closest);

                if (abs(sum - target) < delta) {
                    sum_closest = sum;
                    delta = abs(sum - target);
                }

                // printf(", new 3 sum closest = %d\n", sum_closest);
                if (sum < target)
                    ++i;
                else if (sum > target)
                    --j;
                // sum == target
                else
                    return sum;
            }
        }
        return sum_closest;
    }
};