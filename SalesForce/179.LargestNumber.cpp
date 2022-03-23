#include "../Common.h"


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // greedy, priority queue
        auto comparator = [](string &a, string &b) {
            return a + b < b + a;
        };

        priority_queue<string, vector<string>, decltype(comparator)> pq{ comparator };
        string res;

        for (const int num : nums) {
            pq.push(to_string(num));
        }

        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }

        // special case: [0, 0]
        return res[0] == '0' ? "0" : res;
    }
};