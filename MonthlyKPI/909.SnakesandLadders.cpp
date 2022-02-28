#include "../Common.h"


class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> distances(n * n + 1, -1);
        int target = n * n;
        queue<tuple<int, int>> q({{1, 0}});
        int min_visited = numeric_limits<int>::max();
        while(!q.empty()) {
            int x, distance;
            tie(x, distance) = q.front();
            q.pop();
            if(distances[x] == -1 || distances[x] > distance) {
                distances[x] = distance;
            } else {
                continue;
            }
            int xx, yy;
            tie(xx, yy) = coord(n, x);
            if(board[xx][yy] != -1) {
                x = board[xx][yy];
            }
            if(x == target) {
                min_visited = min(min_visited, distance);
                continue;
            }
                        
            for(int i = 1; i <= 6; i++) {
                int neighbor = x + i;
                if(neighbor <= target && distances[neighbor] == -1) {
                    q.push({neighbor, distance + 1});
                }
            }
        }
        return min_visited == numeric_limits<int>::max() ? -1 : min_visited;
    }
private:
    tuple<int, int> coord(int n, int c) {
        int row = n - 1 - ((c - 1) / n);
        int row_direction = (((n - 1) % 2) == (row % 2));
        int column = c - 1 - ((n - 1 - row) * n);
        column = row_direction ? column : n - column - 1;
        return {row, column};
    }
};