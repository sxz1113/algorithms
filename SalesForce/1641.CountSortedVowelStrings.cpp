#include "../Common.h"


class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> arr {1, 1, 1, 1, 1};

        int res = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < arr.size(); ++j) {
                arr[j] += accumulate(arr.begin() + j + 1, arr.end(), 0);
            }
        }

        return accumulate(arr.begin(), arr.end(), 0);
    }
};