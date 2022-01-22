#include "Common.h"


class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m {
            {'I',    1},
            {'V',    5},
            {'X',   10},
            {'L',   50},
            {'C',  100},
            {'D',  500},
            {'M', 1000}
        };
        int val = m[s[0]];

        for (int i = 1; i < s.size(); ++i) {
            // if (m[s[i]] / m[s[i - 1]] == 5 || m[s[i]] / m[s[i - 1]] == 10)
            if (m[s[i]] > m[s[i - 1]])
                val -= m[s[i - 1]] * 2;

            val += m[s[i]];
        }

        return val;
    }
};