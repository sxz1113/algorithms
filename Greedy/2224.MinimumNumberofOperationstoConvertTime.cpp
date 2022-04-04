#include "../Common.h"


class Solution {
public:
    int convertTime(string current, string correct) {
        istringstream ss(current + ":" + correct);
        vector<int> ts, operations { 60, 15, 5, 1 };
        string s;
        while(getline(ss, s, ':'))
            ts.push_back(stoi(s));

        for (int t : ts)
            cout << t << " ";
        cout << endl;

        int res = 0, i = 0;
        int diff = (ts[2] - ts[0]) * 60 + ts[3] - ts[1];
        while (diff > 0 && i < operations.size()) {
            res += diff / operations[i];
            diff %= operations[i];
            ++i;
        }

        return res;
    }
};

