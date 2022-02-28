#include "../Common.h"


class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int res = 1;
        // j consecutive number starting from i, ending at i + j - 1
        // (i + (i + j - 1)) * j / 2 = n
        for (int i = 2; i < sqrt(2 * n); i++) {
            if ((n - i * (i - 1) / 2) % i == 0)
                res++;
        }
        return res;
    }
};