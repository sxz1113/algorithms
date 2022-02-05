#include "../Common.h"


// recursion
class Solution {
public:
    string countOfAtoms(string formula) {
        int i = 0;
        string res;
        for (const auto it : countAtomsHelper(formula, i)) {
            res += it.first;
            if (it.second > 1)
                res += to_string(it.second);
        }
        return res;
    }

private:
    map<string, int> countAtomsHelper(const string& formula,
                                      int& i) {

        map<string, int> kv;
        while (i < formula.length()) {
            // () -> recursion, or stack
            if (formula[i] == '(') {
                const map<string, int>& kv_ = countAtomsHelper(formula, ++i);
                int count = getCount(formula, i);

                // merge inner frequency table kv_ with outer main table kv
                for (const auto it : kv_) {
                    kv[it.first] += it.second * count;
                }
            } else if (formula[i] == ')') {
                ++i;
                return kv;
            } else {
                const string& element = getElement(formula, i);
                kv[element] += getCount(formula, i);
            }
        }
        return kv;
    }

    string getElement(const string& formula, 
                      int& i) {
        string element;
        while (isalpha(formula[i]) && (element.empty() || islower(formula[i]))) {
            element += formula[i++];
        }

        return element;
    }

    int getCount(const string& formula, int& i) {
        string count;
        while (isdigit(formula[i]))
            count += formula[i++];

        return count.empty() ? 1 : stoi(count);
    }
};
