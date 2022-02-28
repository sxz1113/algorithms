#include "../Common.h"


class Solution {
public:
    bool check(bool h, int x, int y, const vector<vector<char>>& board, const string &word) {
        int i, j, k = word.size();
        if (h) {
            for (j = y; j < y + k; j++)
                if (board[x][j] != ' ' && board[x][j] != word[j - y])
                    return false;
        }
        else {
            for (i = x; i < x + k; i++)
                if (board[i][y] != ' ' && board[i][y] != word[i - x])
                    return false;
        }
        return true;
    }
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        string word_reversed = word;
        reverse(word_reversed.begin(), word_reversed.end());
        
        int i, j, k = word.size(), m = board.size(), n = board[0].size();
        vector<vector<int>> v(m, vector<int>(n, 0)), h(m, vector<int>(n, 0));
        
        for (i = m - 1; i >= 0; i--) {
            for (j = n - 1; j >= 0; j--) {
                if (board[i][j] == '#')
                    continue;
                h[i][j] = v[i][j] = 1;
                if (j + 1 < n) {
                    h[i][j] += h[i][j + 1];
                    h[i][j + 1] = 0;
                }
                if (i + 1 < m) {
                    v[i][j] += v[i + 1][j];
                    v[i + 1][j] = 0;
                }
            }
        }
        
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (h[i][j] == k) {
                    if (check(true, i, j, board, word) || check(true, i, j, board, word_reversed))
                        return true;
                }
                if (v[i][j] == k) {                    
                    if (check(false, i, j, board, word) || check(false, i, j, board, word_reversed))
                        return true;                    
                }
            }
        }
        return false;
    }
};