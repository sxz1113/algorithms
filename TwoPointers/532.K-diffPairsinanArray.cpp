#include "../Common.h"


class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        // edge case
        if (nums.size() < 2)
            return 0;

        int n = nums.size(),
            // 前指针
            i = 0,
            // 后指针
            j = i + 1;
        int delta, res = 0;

        // 先排序
        sort(nums.begin(), nums.end());
        // 滑动窗口
        while (j < n) {
            // 每确定一个指针i，重新定位j = i + 1
            j = i + 1;
            while (j < n && (delta = nums[j] - nums[i]) < k)
                ++j;

            if (j < n && delta == k)
                ++res;

            ++i;
            // 为了避免重复，保证前指针i跳过重复的元素
            while (i > 0 && i < n && nums[i] == nums[i - 1])
                ++i;
        }
        return res;
    }
};