#include "../Common.h"


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 先排序
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();

        for (int i = 0; i < n - 2; ++i) {
            // skip ahead
            // 为了避免重复且提速，对于最外层的循环
            // 略过与之前的重复项
            // 若直接略过第一个重复项，则会漏选结果
            while (i < n - 1 && i > 0 && nums[i] == nums[i - 1])
                ++i;
            
            int j = i + 1, k = n - 1, target = -nums[i];
            while (j < k) {
                int sum = nums[j] + nums[k];
                // 为了避免重复，
                // 仅在确认发现了一组解之后再移动j和k指针略过重复项。
                // 不要先略过重复项再判断是否解成立。
                if (sum < target) {
                    ++j;
                } else if (sum > target) {
                    --k;
                } else {
                    res.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    ++j;
                    --k;
                    while (j < k && nums[j] == nums[j - 1])
                        ++j;

                    while (j < k && nums[k] == nums[k + 1])
                        --k;
                }
            }
        }
        return res;
    }
};