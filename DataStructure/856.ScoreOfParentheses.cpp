#include "../Common.h"


class Solution {
public:
    int scoreOfParentheses(string s) {
        return helper(s, 0, s.size() - 1);
    }

    int helper(string &s,
               int l,
               int r) {
        // base case
        if (r - l == 1)
            return 1;

        int b = 0;
        for (int i = l; i < r; ++i) {
            if (s[i] == '(') ++b;
            if (s[i] == ')') --b;
            if (b == 0)
                return helper(s, l, i) + helper(s, i + 1, r);
        }
        return 2 * helper(s, l + 1, r - 1);
    }
};
