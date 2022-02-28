#include "../Common.h"


class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        bool finished = false;
        int m = board.size(),
            n = board[0].size();
        
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n - 2; ++j){
                int v = abs(board[i][j]);
                if (v != 0 && v == abs(board[i][j + 1]) && v == abs(board[i][j + 2])){
                    board[i][j] = board[i][j + 1] = board[i][j + 2] = -v;
                    finished = true;
                }
            }
        }
        
        for (int i = 0; i < m - 2; ++i){
            for (int j = 0; j < n; ++j){
                int v = abs(board[i][j]);
                if (v != 0 && v == abs(board[i + 1][j]) && v == abs(board[i + 2][j])){
                    board[i][j] = board[i + 1][j] = board[i + 2][j] = -v;
                    finished = true;
                }
            }
        }
        
        for (int j = 0; j < n; ++j){
            int row = n - 1;
            for (int i = m - 1; i >= 0; --i){
                if( board[i][j] > 0)
                    board[row--][j] = board[i][j];
            }
            
            while(row >= 0)
                board[row--][j] = 0;
        }
        
        return finished ? candyCrush(board) : board;
    }
};