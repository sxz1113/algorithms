#include "../Common.h"


class Solution {
public:
    int trap(vector<int>& height) {
        // 维护一个递减栈
        stack<int> stk;

        int res = 0;
        for (int i = 0; i < height.size(); ++i) {
            while (!stk.empty() && height[stk.top()] < height[i]) {
                int base_line = height[stk.top()];
                stk.pop();
                if (stk.empty())
                    continue;

                int w = i - stk.top() - 1;
                int h = min(height[stk.top()], height[i]) - base_line;
                res += w * h;
            }
            stk.push(i);
        }

        return res;
    }
};
