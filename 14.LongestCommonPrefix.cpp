#include "Common.h"


// using sort
class Solution1 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";

        sort(begin(strs), end(strs));
        const string& s1 = strs.front();
        const string& s2 = strs.back();

        int i = 0;
        while (i < s1.size()) {
            if (s1[i] != s2[i])
                break;
            ++i;
        }

        return s1.substr(0, i);
    }
};

// without sort
class Solution2 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";

        string prefix;

        for (int i = 1; i < strs[0].size(); ++i) {
            prefix = strs[0].substr(0, i);
            cout << "scanning for prefix = " << prefix << endl;
            for (string str : strs) {
                if (str.find(prefix) == string::npos) {
                    prefix = strs[0].substr(0, i - 1);
                    return prefix;
                }
            }
        }

        return prefix;
    }
};
