#include "Common.h"


// DP
class SolutionDP {
public:
    int climbStairs(int n) {
        // Jumping frog problem in GA
        vector<int> res(n + 1, 0);
        res[0] = res[1] = 1;
        for (size_t i = 2; i <= n; i++) {
            res[i] = res[i - 1] + res[i - 2];
        }
        
        return res[n];
    }
};

// Memorization
class SolutionMemorization {
public:
    int climbStairs(int n) {
        res = vector<int>(n + 1, 0);
        return helper(n);
    }

private:
    vector<int>res;
    int helper(int n) {
        // boundary conditions
        if (n <= 1) {
            return 1;
        }

        // if there's already a state
        if (res[n] > 0) {
            return res[n];
        }

        res[n] = helper(n - 1) + helper(n - 2);
        return res[n];
    }
};
