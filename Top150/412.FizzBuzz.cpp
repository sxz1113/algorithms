#include "Common.h"


class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans (n);
        for (size_t i = 1; i <= n; i += 1)
            ans[i - 1] = to_string(i);

        for (size_t i = 3; i <= n; i += 3)
            ans[i - 1] = "Fizz";

        for (size_t i = 5; i <= n; i += 5)
            ans[i - 1] = "Buzz";

        for (size_t i = 15; i <= n; i += 15)
            ans[i - 1] = "FizzBuzz";

        return ans;
    }
};
