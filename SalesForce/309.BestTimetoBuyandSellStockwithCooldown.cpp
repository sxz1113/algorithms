#include "../Common.h"


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(),
                rest = 0,
                sold = 0,
                hold = INT_MIN,
                res = 0;

        for (const int price : prices) {
            int sold_prev = sold;
            sold = hold + price;
            hold = max(hold, rest - price);
            rest = max(rest, sold_prev);
            res = max(rest, sold);
        }

        return res;
    }
};