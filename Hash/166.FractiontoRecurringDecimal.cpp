#include "../Common.h"


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // edge case 1: 被除数为0
        if (numerator == 0)
            return "0";

        string s {to_string(numerator / denominator)};
        // 康康符号
        int sign = 1;
        if (numerator < 0) {
            sign *= -1;
            numerator = abs(numerator);
        }

        if (denominator < 0) {
            sign *= -1;
            denominator = abs(denominator);
        }

        if (sign < 0)
            s = "-" + s;

        long rem;
        if ((rem = numerator % denominator) == 0)
            return s;
        s += '.';

        unordered_map<int, int> m;
        while (rem != 0 && m.find(rem) == m.end()) {
            m[rem] = s.size();
            rem *= 10;
            s.push_back('0' + rem / denominator);
            rem %= denominator;
        }

        if (rem == 0)
            return s;

        s.insert(s.begin() + m[rem], '(');
        s.push_back(')');
        return s;
    }
};