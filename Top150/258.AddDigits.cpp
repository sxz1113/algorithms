#include "../Common.h"


class Solution {
public:
    int addDigits(int num) {
        while (num > 10)
            num = addDigitsHelper(num);

        return num;
    }

private:
    int addDigitsHelper(int num) {
        int sum = 0;
        printf("sum of digits of %d = ", num);
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        printf("%d\n", sum);
        return sum;
    }
};
