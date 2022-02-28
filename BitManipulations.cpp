#include "Common.h"


// 461
class Solution {
public:
    int hammingDistance(int x, int y) {
        int check_sum = x ^ y, res = 0;
        while (check_sum) {
            res++;
            check_sum = check_sum & (check_sum - 1);
        }
        return res;
    }
};


// 190
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res;
        for (int i = 0; i < 32; ++i) {
            res = res << 1;
            res += n & 1;
            n = n >> 1;
        }
        return res;
    }
};


//  342
class Solution {
public:
    bool isPowerOfFour(int n) {
        int mask = 0b01010101010101010101010101010101;
        return (n > 0) && !(n & (n - 1)) && (n & mask);
        
    }
};