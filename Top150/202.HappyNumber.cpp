#include "../Common.h"


class Solution {
public:
    bool isHappy(int n) {
        int cnt = 0;
        unordered_map<int, int> res;
        while (n != 1) {
            n = sumOfSquares(n);
            if (res.find(n) != res.end())
                return false;

            res[n] = cnt;
            ++cnt;
        }

        return true;
    }

private:
    int sumOfSquares(int n) {
        cout << "sum of square (" << n << ") = ";
        int sum = 0, i;
        while (n > 0) {
            i = n % 10;
            sum += i * i;
            n /= 10;
        }
        cout << sum << endl;
        return sum;
    }
};