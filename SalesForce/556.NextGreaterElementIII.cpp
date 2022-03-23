#include "../Common.h"


class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        if (!next_permutation_(s))
            return -1;

        long long res = stoll(s);
        return (res > INT32_MAX || res <= n) ? -1 : res;
    }

private:
    bool next_permutation_(string &s) {
        if (s.empty())
            return false;

        int i = s.size() - 1;
        while (i > 0 && s[i - 1] >= s[i])
            i--;

        if (i == 0)
            return false;

        int j = s.size() - 1;
        while (j > 0 && s[j] <= s[i - 1])
            j--;

        swap(s[i - 1], s[j]);
        reverse(s.begin() + i, s.end());
        return true;
    }
};