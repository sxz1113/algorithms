#include "../Common.h"


class Solution {
public:
    int divide(int dividend, int divisor) {
        // edge case
        if (divisor == 0)
            return INT_MAX;

        if (dividend == 0)
            return 0;

        // 变成long long, 以防位数不够
        long long a = abs((long long) dividend);
        long long b = abs((long long) divisor);
        long long c, res = 0;

        // 根据dividend和divisor确定符号
        int sign = 1;
        if (divisor < 0)
            sign *= -1;

        if (dividend < 0)
            sign *= -1;

        // stop condition: divisor野蛮生长到dividend那么大
        // a = sum(b * 2 ^ i)
        // res = sum(2 ^ i)
        while (a >= b) {
            c = b;
            long long cnt = 1;
            // c不停乘以2，直到野蛮生长到a那么大，记录乘以2的次数
            while ((c << 1) <= a) {
                c = c << 1;
                cnt = cnt << 1;
            }
            res += cnt;
            a -= c;
        }

        // 还回符号
        res *= sign;
        return res > INT_MAX ? INT_MAX : res;
    }
};