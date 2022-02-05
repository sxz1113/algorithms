#include "Common.h"


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1,
            end = *max_element(piles.begin(), piles.end()),
            time;

        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            time = finishTime(piles, mid);

            if (time <= h) {
                end = mid;

            // eating way too slow
            } else {
                start = mid;
            }
        }

        if ((time = finishTime(piles, start)) <= h)
            return start;

        if ((time = finishTime(piles, end)) <= h)
            return end;

        return -1;
    }

private:
    int finishTime(vector<int> &piles, int speed) {
        int time = 0;

        for (int pile : piles) {
            time += ceil(1.0 * pile / speed);
        }

        return time;
    }
};
