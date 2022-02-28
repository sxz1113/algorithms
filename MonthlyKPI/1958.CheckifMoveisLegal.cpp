#include "../Common.h"


class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        vector<pair<int, int>> directions {
            { 0,  1},
            { 0, -1},
            { 1,  0},
            {-1,  0},
            { 1,  1},
            {-1, -1},
            {-1,  1},
            { 1, -1}
        };

        int check_sum = 0, r, c, m = board.size(), n = board[0].size();
        for (int i = 0; i < directions.size(); ++i) {
            // check 8 directions
            r = rMove + directions[i].first;
            c = cMove + directions[i].second;
            check_sum = 0;
            while (r >= 0 && r < m && c >= 0 && c < n) {
                if (board[r][c] == '.') {
                    break;
                } else if (board[r][c] != color) {
                    check_sum++;
                } else if (board[r][c] == color){
                    if (check_sum < 1) break;
                    else return true;
                }
                r += directions[i].first;
                c += directions[i].second;
            }
            // reset check sum after checking one direction
            check_sum = 0;
        }
        return false;
    }
};