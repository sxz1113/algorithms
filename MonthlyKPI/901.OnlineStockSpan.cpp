#include "../Common.h"


class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int res = 1;
        while (!stk_.empty() && stk_.top().first <= price) {
            // accumulate the span
            res += stk_.top().second;
            stk_.pop();
        }

        stk_.push({price, res});
        return res;
    }

private:
    stack<pair<int, int>> stk_;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */