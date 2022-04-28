#include "../Common.h"


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        // slicing window 滚动滑窗处理
        // t - target distance
        // k - 滑窗大小
        multiset<long> s;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k)
                s.erase((long) nums[i - k - 1]);

            auto iter = s.lower_bound((long) nums[i] - t);
            if (iter != s.end() && *iter - nums[i] <= t)
                return true;

            s.insert((long) nums[i]);
        }

        return false;
    }
};
