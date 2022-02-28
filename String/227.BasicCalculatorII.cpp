#include "../Common.h"


class Solution {
public:
    int calculate(string s) {
        int prev = 0, cur = 0, i = 0, res = 0;
        // preset first op = '+'
        char op = '+';
        while (i < s.size()) {
            if (isdigit(s[i])) {
                // parse digits
                cur = parseInteger(s, i);
                // execute operation, record prev
                prev = executeOperation(op, res, cur, prev);
                continue;
            } else if (s[i] == ' ') {
            } else {
                op = s[i];
            }
            i++;
        }
        return res + prev;
    }

private:
    int parseInteger(const string& s, int& i) {
        int n = 0;
        while (i < s.size() && isdigit(s[i])) {
            n = n * 10 + (s[i++] - '0');
        }
        return n;
    }

    int executeOperation(const char& op,
                         int& res,
                         int& cur,
                         int prev) {
        switch (op) {
            case '+':
                res += prev;
                prev = cur;
                break;

            case '-':
                res += prev;
                prev = -cur;
                break;

            case '*':
                prev *= cur;
                break;

            case '/':
                prev /= cur;
                break;

            default:
                break;
        }

        return prev;
    }
};
