#include "Common.h"


class Solution {
public:
    string convert(string s, int numRows) {
        // edge case
        if (numRows <= 2)
            return s;

        string *str = new string[numRows];

        int row = 0, step = 1;
        for (char c : s) {
            str[row].push_back(c);

            if (row == numRows - 1)
                step = -1;

            if (row == 0)
                step = 1;

            row += step;
        }

        s.clear();
        for (int i = 0; i < numRows; ++i)
            s.append(str[i]);

        delete[] str;
        return s;
    }
};
