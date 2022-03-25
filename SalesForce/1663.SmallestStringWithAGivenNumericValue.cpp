#include "../Common.h"


class Solution {
public:
    string getSmallestString(int n, int k) {
        constexpr int LEN = 26;
        string s("");
        for (int i = 1; i <= n; ++i) {
            int quota = LEN * (n - i);
            int c = max(1, (k - quota));
            s += (char) ('a' + c - 1);
            k -= c;
        }
        return s;
    }
};