#include "../Common.h"


class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int min_diff = INT32_MAX, diff;
        vector<vector<int>> res;

        for (int i = 1; i < arr.size(); ++i) {
            diff = arr[i] - arr[i - 1];
            if (diff > min_diff) {
                continue;

            } else if (diff < min_diff) {
                min_diff = diff;
                res.clear();
            }

            res.push_back({arr[i - 1], arr[i]});
        }
        return res;
    }
};