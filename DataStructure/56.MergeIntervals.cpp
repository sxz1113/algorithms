#include "../Common.h"


class SolutionNoSort {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res { intervals[0] };
        const int lower = 0, upper = 1;
        bool merged;

        for (int i = 1; i < intervals.size(); ++i) {
            merged = false;
            for (int j = 0; j < res.size(); ++j) {
                if ((res[j][lower] <= intervals[i][lower] && intervals[i][lower] <= res[j][upper]) ||
                    (intervals[i][lower] <= res[j][lower] && res[j][lower] <= intervals[i][upper])) {
                    printf("merge intervals (%d, %d) with res (%d, %d) on right\n",
                        intervals[i][0], 
                        intervals[i][1],
                        res[j][0],
                        res[j][1]);
                    res[j][lower] = min(intervals[i][lower], res[j][lower]);
                    merged = true;
                }

                if ((res[j][lower] <= intervals[i][upper] && intervals[i][upper] <= res[j][upper]) ||
                    (intervals[i][lower] <= res[j][upper] && res[j][upper] <= intervals[i][upper])) {
                    printf("merge intervals (%d, %d) with res (%d, %d) on left\n",
                        intervals[i][0], 
                        intervals[i][1],
                        res[j][0],
                        res[j][1]);
                    res[j][upper] = max(intervals[i][upper], res[j][upper]);
                    merged = true;
                }
            }
            if (!merged) res.push_back(intervals[i]);
        }

//      res vector might contain duplicated list and overlapped list
        sort(res.begin(), res.end() );
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res {intervals[0]};

        for (int i = 1; i < intervals.size(); ++i) {
            for (int j = 0; j < res.size(); ++j) {
                if(res.back()[1] >= intervals[i][0])
                    res.back()[1] = max(res.back()[1], intervals[i][1]);
                else res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
