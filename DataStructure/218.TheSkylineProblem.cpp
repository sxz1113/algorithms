#include "../Common.h"
#define L 0
#define R 1
#define H 2


class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        priority_queue<pair<int, int>> pq;
        int i = 0, n = buildings.size();
        int cur_x, cur_h;
        while (i < n || !pq.empty()) {
            if (pq.empty() || i < n && buildings[i][L] <= pq.top().second) {
                cur_x = buildings[i][L];
                while (i < n && cur_x == buildings[i][L]) {
                    pq.push({buildings[i][H], buildings[i][R]});
                    ++i;
                }
            } else {
                cur_x = pq.top().second;
                while (!pq.empty() && cur_x >= pq.top().second)
                    pq.pop();
            }

            cur_h = pq.empty() ? 0 : pq.top().first;
            if (res.empty() || cur_h != res.back()[1])
                res.push_back({cur_x, cur_h});
        }

        return res;
    }
};