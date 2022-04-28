#include "../Common.h"


class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        int m = left.size(),
            n = right.size();

        int ll = pow(10, max(0, (int) m / 4 - 1)),
            rr = pow(10, max(0, (int) n / 4 + 1));

        long long l = stoll(left),
            r = stoll(right);

        vector < bool > types {
            false,
            true
        };

        int res = 0;
        for (int i = ll; i <= rr; ++i) {
            for (bool type: types) {
                long long palindrome = getPalindrome(i, type);
                if (palindrome > 1e9)
                    continue;

                palindrome *= palindrome;
                // cout << " => " << palindrome << endl;
                if (palindrome < l || palindrome > r)
                    continue;

                if (isPalindrome(palindrome)) {
                    // cout << "palindrome = " << palindrome << endl;
                    ++res;
                }
            }
        }
        return res;
    }

private:
    long long getPalindrome(int n, bool is_odd) {
        long long res = n;
        // cout << n << " => ";
        if (is_odd)
            n /= 10;

        while (n > 0) {
            res = res * 10 + n % 10;
            n /= 10;
        }

        // cout << res;
        return res;
    }

    bool isPalindrome(long long n) {
        long long n0 = n, n1 = 0;
        while (n > 0) {
            n1 = n1 * 10 + n % 10;
            n /= 10;
        }

        // cout << "n0 = " << n0 << " n1 = " << n1 << endl;
        return n0 == n1;
    }
};