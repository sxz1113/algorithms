#include "../Common.h"


class Solution {
public:
    // greedy, 2 pointers
    int numRescueBoats(vector<int>& people, int limit) {
        int res = 0, 
            n = people.size(),
            i = 0,
            j = n - 1;
        sort(people.begin(), people.end());
        while (i <= j) {
            if (people[i] + people[j] <= limit)
                ++i;

            // heavier the first
            --j;
            ++res;
        }
        return res;
    }
};