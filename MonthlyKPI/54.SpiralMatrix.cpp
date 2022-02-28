#include "../Common.h"


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const vector<vector<int>> directions{
            { 0,  1},
            { 1,  0},
            { 0, -1},
            {-1,  0}
        };
        vector<int> res;
        int nrow = matrix.size() - 1,
            ncol = matrix[0].size();

        if ((nrow + 1) == 0 || ncol == 0)
            return res;

        vector<int> counter {ncol, nrow};
        int steps = 0, nr = 0, nc = -1;
        while (counter[steps % 2]) {
            for (int i = 0; i < counter[steps % 2]; ++i) {
                nr += directions[steps][0];
                nc += directions[steps][1];
                res.push_back(matrix[nr][nc]);
            }
            counter[steps % 2]--;
            steps = (steps + 1) % 4;
        }
        
        return res;
    }
};
