#include "../Common.h"


class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Tag: priority queue

        int n = events.size(),
            res = 0,
            day = 0,
            i = 0;

        constexpr int ST = 0, ED = 1;

        // push active events to priority queue
        priority_queue<int, vector<int>, greater<int>> pq;

        sort(events.begin(), events.end());
        while (!pq.empty() || i < n) {
            if (pq.empty()) {
                day = events[i][ST];
                printf("current active day = %d\n", day);
            }

            // enqueue all events starting at current active day
            while (i < n && events[i][0] == day) {
                pq.push(events[i][ED]);
                printf("enqueue %dth event [%d, %d]\n", 
                    i, 
                    events[i][ST], 
                    events[i][ED]);
                i++;
            }

            // remove event with the earlist end day
            printf("remove event ends at %d\n", pq.top());
            pq.pop();
            res++;
            day++;

            // remove rest events
            while (!pq.empty() && pq.top() < day) {
                printf("remove event ends at %d\n", pq.top());
                pq.pop();
            }
        }

        return res;
    }
};