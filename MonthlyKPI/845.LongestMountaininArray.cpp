#include "../Common.h"


class Solution {
public:
    // two pointers
    int longestMountain(vector<int>& arr) {
        int n = arr.size(), 
            res = 0, 
            left = 0, 
            right = 0;

        for (int i = 1; i < arr.size(); ++i) {
            // if carry over lefts
            if (right && arr[i - 1] < arr[i] || arr[i - 1] == arr[i])
                left = right = 0;

            left += arr[i - 1] < arr[i];
            right += arr[i - 1] > arr[i];
            if (left && right) {
                res = max(res, left + right + 1);
            }
        }

        return res;
    }
};