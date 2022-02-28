#include "../Common.h"


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(),
            n = board[0].size();

        // edge case
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool dfs(vector<vector<char>>& board,
             const string& word,
             int i,
             int j,
             int k) {
        // break condition:
        int m = board.size(),
            n = board[0].size();

        if (k == word.size())
            return true;

        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k]) {
            return false;
        }

        // if match
        board[i][j] = '*';
        bool match = dfs(board, word, i, j + 1, k + 1) || 
                     dfs(board, word, i, j - 1, k + 1) || 
                     dfs(board, word, i + 1, j, k + 1) || 
                     dfs(board, word, i - 1, j, k + 1);

        // backtrack
        board[i][j] = word[k];
        return match;
    }
};
