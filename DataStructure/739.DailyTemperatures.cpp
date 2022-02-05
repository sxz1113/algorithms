#include "../Common.h"


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<int> st;
        int n = temperatures.size();

        // st.push(temperatures.front());
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i])
                st.pop();

            if (!st.empty())
                res[i] = st.top() - i;

            st.push(i);
        }
        return res;
    }
};


class SolutionBruteForce {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> res;
        bool warm_ahead;
        for (int i = 0; i < temperatures.size() - 1; ++i) {
            warm_ahead = false;
            for (int j = i + 1; j < temperatures.size(); ++j) {
                if (temperatures[j] > temperatures[i]) {
                    res.push_back(j - i);
                    // printf("j - i = %d - %d = %d\n", j, i, j - i);
                    warm_ahead = true;
                    break;
                }
            }
            if (!warm_ahead) {
                res.push_back(0);
                // printf("No warm temperature ahead - %d\n", i);
            }
        }
        res.push_back(0);
        return res;
    }
};
