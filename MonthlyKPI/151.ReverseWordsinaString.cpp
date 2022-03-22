#include "../Common.h"


class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        string words;

        // manual string parsing
        // int i = 0;
        // while (i < s.size()) {
        //     string word;
        //     while (i < s.size() && s[i] == ' ')
        //         ++i;

        //     while (i < s.size() && s[i] != ' ')
        //         word.push_back(s[i++]);

        //     if (!word.empty())
        //         stk.push(word);
        // }

        // using stringstream
        stringstream ss(s);
        string word;
        while (ss >> word) {
            stk.push(word);
        }

        while (!stk.empty()) {
            words += stk.top();
            stk.pop();
            if (!stk.empty())
                words += " ";
        }

        return words;
    }
};