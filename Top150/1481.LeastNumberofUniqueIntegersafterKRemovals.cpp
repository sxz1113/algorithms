#include "../Common.h"


class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // count frequencies, rm least frequent number
        unordered_map<int, int> freq;
        vector<int> v;
        for (const int &i : arr) {
            freq[i]++;
        }

        // use min heap, or sort vector of pairs
        for (const auto &kv : freq) {
            v.push_back(kv.second);
        }

        sort(v.begin(), v.end(), greater<int>());
        int i = v.size() - 1;
        while (k > 0 && i >=0 ) {
            printf("k = %d, i = %d, v[i] = %d\n", k, i, v[i]);
            k -= v[i];
            i--;
        }

        cout << "k = " << k << endl;
        return k < 0 ? i + 2 : i + 1;
    }
};