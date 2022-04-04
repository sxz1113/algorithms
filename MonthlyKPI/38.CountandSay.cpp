#include "../Common.h"


class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";

        string s = countAndSay(n - 1),
               res {};

        int i = 0, j;
        while (i < s.size()) {
            j = i;
            while (i < s.size() && s[i] == s[j]) {
                i++;
            }
            res += to_string(i - j) + s[j];
        }

        return res;
    }
};