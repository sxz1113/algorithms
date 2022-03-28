#include "../Common.h"


class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length, 0);
        int m = updates.size();
        
        // // intuitive solution: brute-force
        // for (const vector<int> &update : updates) {
        //     for (int i = update[0]; i <= update[1]; ++i) {
        //         res[i] += update[2];
        //     }
        // }
        
        // updated solution: prefix_sum / accumulate sum
        // update / increase start index and decrease end index
        for (const vector<int> &update : updates) {
            res[update[0]] += update[2];
            int stop = update[1] + 1;
            if (stop < length)
                res[stop] -= update[2]; 
        }
        
        // accumulate
        for (int i = 1; i < length; ++i) {
            res[i] += res[i - 1];
        }
        return res;
    }
};