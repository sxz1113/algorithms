#include "../Common.h"


class Solution {
public:
    const int M = 1000000007;
    int numOfSubarrays(vector<int>& arr) {
        // prefix sum
        // 当前数之前的prefix sum里出现过多少次奇数, 出现过多少次偶数}
        vector<int> counter{0, 1};
        int sum = 0, res = 0;
        for (const int num : arr) {
            sum += num % 2;
            int i = sum % 2;
            res = (res + counter[i]) % M;
            ++counter[(i + 1) % 2];
        }
        return res;
    }
};
