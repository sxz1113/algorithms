#include "../Common.h"


class Solution {
public:
    int primePalindrome(int n) {
        // edge case 11
        if (n == 11)
            return n;

        // 搜寻所有大于N的回文数，然后查看它们是否是质数
        int i = n, res;
        int res_min = pow(10, to_string(n).size() / 2);
        while (i < 2 * 10e4) {
            res = getPalindrome(i);
            if (res < res_min)
                continue;

            if (isPrime(res)) {
                return res;
            }
        }

        return -1;
    }

private:
    int getPalindrome(int n) {
        int res = n;
        n /= 10;
        while (n > 0) {
            res = res * 10 + n % 10;
            n /= 10;
        }

        return res;
    }

    bool isPrime(int n) {
        if (n == 1)
            return false;

        if (n % 2 == 0)
            return n == 2;

        for (int i = 3; i <= sqrt(n); i+=2)
            if (n % i == 0)
                return false;

        return true;
    }
};