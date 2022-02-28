#include "../Common.h"

// tag: DP
class Solution {
public:
    bool isMatch(string s, string p) {
        /**
         * @brief subproblem: T[i][j] := if s[0:i] matches p[j]
         * 1. T[i][j] = T[i - 1][j - 1] && (s[i] == p[j] || p[j] == '.')
         * 2
         * 
         *       p[j - 1] repeats 0 times and matches empty
         *        
         */
        int i = 0, j = 0;
        while (i < s.size()) {
            if (j >= p.size())
                return false;

            if (isalnum(p[j])) {
                if (s[i] == p[j]) {
                    ++i;
                    ++j;
                } else {
                    return false;
                }
            } else if (p[j] == '*') {
                while (i < s.size() && s[i] == p[j - 1] || p[j - 1] == '.') 
                    ++i;
            } else if (p[j] == '.') {
                ++j;
                ++i;
            }
        }
        return true;
    }
};