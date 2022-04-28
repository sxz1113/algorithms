#include "../Common.h"

#define mod 1000000007

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        // 二分搜索一个value，使得对于任意比value小的num，sum(value - num)最大
        int lower = 0,
            upper = 1e7;

        long incr;
        while (lower < upper) {
            int m = lower + (upper - lower) / 2;
            incr = 0;
            for (int num : nums)
                incr += max(m - num, 0);

            if (incr <= (long) k)
                lower = m + 1;
            else
                upper = m;
        }

        cout << "best value: " << lower << endl;
        
        for (int num : nums) {
            k -= max(0, lower - 1 - num);
        }
        
        long long int prod = 1;
        for (int num : nums) {
            if (num < lower) {
                if (k > 0){
                    prod = prod * lower % mod;
                    --k;
                } else {
                    prod = prod * (lower - 1) % mod;
                }
            } else {
                prod = prod * num % mod;
            }
        }
        return (int) prod;
    }
};