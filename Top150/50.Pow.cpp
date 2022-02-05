#include "../Common.h"


class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        while (n) {
            if (n % 2)
                res = n > 0 ? res * x : res / x;
            x = x * x;
            printf("n = %d, n %% 2 = %d, x = %f\n", 
                   n, 
                   n % 2, 
                   res);
            n /= 2;
        }
        return res;
    }
};
