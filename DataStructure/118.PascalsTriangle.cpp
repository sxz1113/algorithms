#include "../Common.h"


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        for (size_t i = 0; i < numRows; i++) {
            vector<int> tmp(i  + 1, 1);
            for (int j = 1; j < i; ++j) {
                tmp[j] = res[i - 1][j - 1] + res[i - 1][j];
            }
            res.emplace_back(tmp);
        }

        return res;
    }
};