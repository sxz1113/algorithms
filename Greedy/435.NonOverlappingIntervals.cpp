#include "../Common.h"


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto cmp = [] (vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        };

        sort(intervals.begin(), intervals.end(), cmp);
        int res = 0;
        // last interval might be dropped, 
        // need another interval to record most recent interval
        vector<int>& prev = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if (prev[1] > intervals[i][0]) {
                res++;
            } else {
                prev = intervals[i];
            }
        }
        return res;
    }
};