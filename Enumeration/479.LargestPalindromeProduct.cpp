#include "../Common.h"


class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1)
            return 9;

        long long palindrome = 0L;
        long long i_max = pow(10, n) - 1;
        long long i_min = pow(10, n - 1);
        // 列出所有n位数，构造出对应的2n位数的回文数
        for (long long i = i_max; i >= i_min; --i) {
            palindrome = getPalindrome(i);
            // 依次尝试是否能被n位数除尽，且商仍然是n位数
            for (long long divisor = sqrt(palindrome); divisor <= i_max; ++divisor) {
                long long dividend = palindrome / divisor;
                long long remainder = palindrome % divisor;
                if (remainder == 0 && 
                    dividend <= i_max &&
                    dividend > i_min) {
                    return palindrome % 1337;
                }
            }
        }

        return -1;
    }

private:
    // 根据n，构造对应双倍长度的palindrome，优先考虑偶数长度
    long long getPalindrome(long long n) {
        // cout << "n = " << n << " => ";
        long long res = n;

        while (n > 0) {
            res = res * 10 + n % 10;
            n /= 10;
        }

        // cout << res << endl;
        return res;
    }
};