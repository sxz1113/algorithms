#include "../Common.h"


class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int res = 0;

        // 先排序
        sort(nums.begin(), nums.end());

        // 固定最大的位置k
        for (int k = 2; k < n; ++k) {
            // 搜索i, j => 2sum larger
            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    res += (j - i);
                    --j;
                } else {
                    ++i;
                }
            }
        }
        return res;
    }
};
