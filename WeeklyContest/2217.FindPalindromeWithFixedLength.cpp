#include "../Common.h"


class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<long long> res(queries.size(), -1);
        int n = queries.size();
        int half_len = (intLength + 1) / 2;
        int max_queries = 9 * pow(10L, half_len - 1);
        long start = pow(10L, (intLength - 1) / 2);
        // printf("half len = %d, max query = %d\n", 
        //        half_len, 
        //        max_queries);

        for (int i = 0; i < n; ++i) {
            if (queries[i] <= max_queries) {
                res[i] = generate_palindrome(start + queries[i] - 1, intLength % 2);
            }
        }
        return res;
    }

private:
    long long generate_palindrome(long long half, bool is_odd) {
        long long res = half;
        if (is_odd)
            half /= 10;

        while (half > 0) {
            res = res * 10 + half % 10;
            half /= 10;
        }

        return res;
    }
};