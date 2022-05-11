#include "../Common.h"


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;

        if (m == 0 || n == 0)
            return res;
        // vector of histogram
        vector<int> histogram(n, 0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                histogram[j] = matrix[i][j] == '1' ? histogram[j] + 1 : 0;
            }
            res = max(res, helper(histogram));
        }

        return res;
    }

private:
    int helper(vector<int> &histogram) {
        stack<int> stk;
        stk.push(0);
        int res = 0;
        for (int i = 0; i <= histogram.size(); ++i) {
            int hist = (i == histogram.size()) ? 0 : histogram[i];
            while (!stk.empty() && hist < histogram[stk.top()]) {
                int h = histogram[stk.top()];
                stk.pop();
                int w = stk.empty() ? i : i - stk.top() - 1;
                res = max(res, h * w);
            }
            stk.push(i);
        }

        return res;
    }
};
