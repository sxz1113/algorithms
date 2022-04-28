#include "../Common.h"


class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        int res = 0;
        int singular = 0;
        for (char &c : s)
            m[c] += 1;

        for (auto &kv : m) {
            if(kv.second % 2 == 1) {
                singular = 1;
                --kv.second;
            }

            res += kv.second;
        }

        return res + singular;
    }
};