#include "../Common.h"


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;

        // edge case:
        if (nums.size() < 4)
            return res;

        // 先排序
        sort(nums.begin(), nums.end());
        // 再搜索
        for (int i = 0; i < n - 3; ++i) {
            // 去重，避免i, j重复
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            // 剪枝，确定在搜索范围内可以有解
            if (accumulate(nums.begin() + i, nums.begin() + i + 4, 0) > target)
                break;

            if (accumulate(nums.end() - 3, nums.end(), nums[i]) < target)
                continue;

            for (int j = i + 1; j < n - 2 ; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                // 剪枝，确定在搜索范围内可以有解
                if (accumulate(nums.begin() + j, nums.begin() + j + 3, nums[i]) > target)
                    break;

                if (nums[i] + nums[j] + nums[n - 2] + nums[n -1] < target)
                    continue;

                int k = j + 1;
                int l = n - 1;
                while(k < l) {
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum > target) {
                        --l;
                    } else if (sum < target) {
                        ++k;
                    } else {
                        res.push_back(vector<int>{nums[i], nums[j], nums[k], nums[l]});
                        ++k;
                        --l;
                        while (k < l && nums[k] == nums[k - 1])
                            ++k;

                        while (k < l && nums[l] == nums[l + 1])
                            --l;
                    }
                }
            }
        }
        return res;
    }
};