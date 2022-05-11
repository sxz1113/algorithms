#include "../Common.h"


class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // 1 - index i
        // 3 - index k
        // 2 - index j
        // 从后往前遍历 k, 找到满足nums[j] < nums[k]中 j的最大值
        // （namely 最靠近k的j，greedily expand [0, j - 1] 的范围）
        int n = nums.size();
        vector<int> prev_min(n, 0);

        prev_min[0] = INT_MAX;
        for (int i = 1; i < n; ++i) {
            prev_min[i] = min(prev_min[i - 1], nums[i - 1]);
        }

        // 从后往前遍历j, stack储存 k
        stack<int> stk;
        for (int j = n - 1; j >= 0; --j) {
            // stk.top(): k
            while (!stk.empty() && nums[stk.top()] < nums[j]) {
                if (prev_min[j] < nums[stk.top()])
                    return true;
                stk.pop();˜
            }
            stk.push(j);
        }

        return false;
    }
};