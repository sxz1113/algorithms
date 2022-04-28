#include "../Common.h"


class Solution {
public:
    vector<string> v3 {
        "Billion",
        "Million",
        "Thousand"
    };

    string numberToWords(int num) {
        if (num == 0)
            return v1[0];

        string res = itos(num);
        return res.substr(1);
    }

private:
    static const vector<string> v1, v2;
    static const int ONE = 1;
    static const int TEN = 10;
    static const int TWENTY = 20;
    static const int HUNDRED = 100;
    static const int THOUSAND = 1000;
    static const int MILLION = 1000000;
    static const int BILLION = 1000000000;

    string itos(int n) {
        if (n >= BILLION) {
            return itos(n / BILLION) + " Billion" + itos(n % BILLION);
        } else if (n >= MILLION) {
            return itos(n / MILLION) + " Million" + itos(n % MILLION);
        } else if (n >= THOUSAND) {
            return itos(n / THOUSAND) + " Thousand" + itos(n % THOUSAND);
        } else if (n >= HUNDRED) {
            return itos(n / HUNDRED) + " Hundred" + itos(n % HUNDRED);
        } else if (n >= TWENTY) {
            return " " + v2[n / 10] + itos(n % 10);
        } else if (n >= 1) {
            return " " + v1[n];
        } else {
            return "";
        }
    }
};

const vector<string> Solution::v1 ({
    "Zero",
    "One",
    "Two",
    "Three",
    "Four",
    "Five",
    "Six",
    "Seven",
    "Eight",
    "Nine",
    "Ten",
    "Eleven",
    "Twelve",
    "Thirteen",
    "Fourteen",
    "Fifteen",
    "Sixteen",
    "Seventeen",
    "Eighteen",
    "Nineteen"
});

const vector<string> Solution::v2 ({
    "Zero",
    "Ten",
    "Twenty",
    "Thirty",
    "Forty",
    "Fifty",
    "Sixty",
    "Seventy",
    "Eighty",
    "Ninety"
});
