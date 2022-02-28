#include "../Common.h"


class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        // edge case, if length of num is less than / equals k,
        // rm all digits
        if (n <= k)
            return "0";

        if (k == 0)
            return num;

        // use stack to track min digits possible
        stack<char> stk;

        // string to return
        string res (n - k, ' ');

        for (char& c : num) {
            while (!stk.empty() && k > 0 && stk.top() > c) {
                printf("pop %c out of stack\n", stk.top());
                stk.pop();
                k--;
            }

            if (!stk.empty() || c != '0') {
                stk.push(c);
                printf("push %c on to stack\n", stk.top());
            }
        }

        // pop remaining k digits out of stack
        while (!stk.empty() && k--) {
            printf("pop %c out of stack\n", stk.top());
            stk.pop();
        }

        if (stk.empty())
            return "0";

        int i = res.size();
        while (!stk.empty()) {
            res[--i] = stk.top();
            stk.pop();
        }

        return res.substr(i);
    }
};