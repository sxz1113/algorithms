#include "../Common.h"


class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // dp两种状态，买不买，卖不卖
        // 两种计费，买入时交transaction fee vs 卖出时交
        int hold = INT_MIN, sold = 0;
        int tmp;

        for (int const &price : prices) {
            tmp = sold;
            hold = max(hold, tmp - price - fee);
            sold = max(sold, hold + price);
        }
        return sold;
    }
};
