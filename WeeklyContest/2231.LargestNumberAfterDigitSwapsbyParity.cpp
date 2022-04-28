#include "../Common.h"


class Solution {
public:
    int largestInteger(int num) {
        vector<int> v, even, odd;
        int i, n = num;
        while (n > 0) {
            i = n % 10;
            n /= 10;
            if (i % 2 == 0) {
                even.push_back(i);
                v.push_back(1);
            } else {
                odd.push_back(i);
                v.push_back(0);
            }
        }

        sort(even.begin(), even.end(), greater<int>());
        sort(odd.begin(), odd.end(), greater<int>());
        int j = 0, k = 0, res = 0;
        for (int i = v.size() - 1; i >= 0; --i) {
            res *= 10;
            if (v[i] == 1) {
                res += even[j];
                ++j;
            } else {
                res += odd[k];
                ++k;
            }
        }

        return res;
    }
};