#include "../Common.h"


class Solution {
public:
    int arrangeCoins(int n) {
        return floor(sqrt((double)2 * n + 0.25) - 0.5);
    }
};