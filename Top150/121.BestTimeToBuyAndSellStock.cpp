#include "Common.h"


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int price_min = INT_MAX;

        for (int i = 0; i < prices.size(); ++i) {
            price_min = min(price_min, prices[i]);
            res = max(res, prices[i] - price_min);
        }

        return res;
    }
};
