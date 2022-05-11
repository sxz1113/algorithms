#include "../Common.h"


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 维护一个递增栈
        stack<int> stk;
        // 在height数组首添加元素0 -> 预防空栈
        stk.push(0);
        int res = 0;
        for (int i = 0; i <= heights.size(); ++i) {
            // 在height数组末添加元素0 -> 保证最后强制回溯
            int height = (i == heights.size()) ? 0 : heights[i];
            while (!stk.empty() && heights[stk.top()] >= height) {
                int h = heights[stk.top()];
                // 提取次顶元素的位置
                stk.pop();
                int w = stk.empty() ? i : i - stk.top() - 1;
                res = max(res, w * h);
            }
            stk.push(i);
        }

        return res;
    }
};