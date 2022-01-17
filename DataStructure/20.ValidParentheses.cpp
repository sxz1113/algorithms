#include "Common.h"


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char &c : s) {
            switch (c) {
            case '(':
                st.push(')');
                break;

            case '[':
                st.push(']');
                break;

            case '{':
                st.push('}');
                break;

            default:
                if (st.empty() || c != st.top())
                    return false;
                else
                    st.pop();
                break;
            }
        }
        return st.empty() ? true : false;
    }
};
