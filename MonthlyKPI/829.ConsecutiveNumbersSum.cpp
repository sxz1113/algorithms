#include "../Common.h"


class Solution {
public:
    int consecutiveNumbersSum(int n) {
        // consecutive numbers sum includes self
        int res = 1;
        // j consecutive number starting from i, ending at i + j - 1
        // (i + (i + j - 1)) * j / 2 = n
        // range of j : 
        //    lower bound - 2, at least two numbers, or self
        //    upper bound - j ^ 2 - j = 2 * n - i ^ 2 -> j ^ 2 <= sqrt(2 * n)
        for (int j = 2; j < sqrt(2 * n); ++j) {
            if ((n - j * (j - 1) / 2) % j == 0)
                res++;
        }
        return res;
    }
};