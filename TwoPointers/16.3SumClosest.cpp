#include "../Common.h"


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // edge case
        if (nums.size() == 3)
            return accumulate(nums.begin(), nums.end(), 0);

        // 先排序
        sort(nums.begin(), nums.end());

        int delta = 1e4, res, n = nums.size();

        // 先固定第一项
        for (int i = 0; i < n - 2; ++i) {
            // 外层去重
            while (i > 0 && i < n - 2 && nums[i - 1] == nums[i])
                ++i;

            // 双指针搜索第二、第三项
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                int delta_cur = abs(sum - target);
                if (delta_cur < delta) {
                    delta = delta_cur;
                    res = sum;
                }

                if (sum > target) {
                    --k;
                } else if (sum < target) {
                    ++j;
                } else {
                    return target;
                }
            }
        }

        return res;
    }
};