#include "Common.h"


class Solution {
private:
    const vector<int> integers {
        1000, 900, 500, 400,
        100,   90,  50,  40,
        10,    9,   5,    4,
        1
    };
    const vector<string> romans {
        "M", "CM", "D", "CD",
        "C", "XC", "L", "XL",
        "X", "IX", "V", "IV",
        "I"
    };

public:
    string intToRoman(int num) {
        string s;

        for (int i = 0; i < integers.size(); ++i) {
            for (int j = 0; j < num / integers[i]; ++j) {
                s += romans[i]; 
            }
            num %= integers[i];
        }
        return s;
    }
};
