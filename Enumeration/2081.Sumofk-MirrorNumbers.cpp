#include "../Common.h"


// brute force -- as k and n are small
class Solution {
public:
    long long kMirror(int k, int n) {
        long long res = 0,
                  k_mirror_num = 0;

        // enumerate possible k-mirror numbers
        int odd = 1, even = 1;
        while (n-- > 0) {
            long long num_0 = getBase10MirrorNum(even, false);
            long long num_1 = getBase10MirrorNum(odd, true);
            while (!isMirror(num_1, k)) {
                num_1 = getBase10MirrorNum(++odd, true);
            }

            while (num_0 < num_1 && !isMirror(num_0, k)) {
                num_0 = getBase10MirrorNum(++even, false);
            }

            if (num_0 < num_1) {
                res += num_0;
                ++even;
            } else {
                res += num_1;
                ++odd;
            }
        }
        return res;
    }

private:
    long long getBase10MirrorNum(int n, bool is_odd) {
        // if the length of palindrome is odd: n = 521 -> 52125
        // if the length of palindrome is even: n = 521 -> 521125
        long long res = n;
        if (is_odd)
            n /= 10;

        while (n > 0) {
            res = res * 10 + n % 10;
            n /= 10;
        }

        return res;
    }

    bool isMirror(const long long n, int k) {
        long long res = 0, tmp = n;
        while (tmp > 0) {
            res = res * k + tmp % k;
            tmp /= k;
        }

        return res == n;
    }
};