#include "../Common.h"


class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int res = 0;
        stk.push(-1);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')') {
                if (!stk.empty() && s[stk.top()] == '(') {
                    stk.pop();
                    res = max(res, i - stk.top());
                } else {
                    stk.push(i);
                }
            }
        }
        return res;
    }
};
