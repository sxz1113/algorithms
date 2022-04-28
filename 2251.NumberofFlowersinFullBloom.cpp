#include "Common.h"


class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        map<int, int> diff;
        // 用变化量表示一段区间上的更新，即在时间点start (+ 1朵小红花), 
        // 在end + 1 （-1朵小红花） 
        for (const vector<int> &flower : flowers) {
            ++diff[flower[0]];
            --diff[flower[1] + 1];
        }

        // 根据person，排序id索引
        int n = persons.size();
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);
        cout << "before sorting" << endl;
        for (int id : ids) {
            cout << id << ", ";
        }
        cout << endl;

        sort(ids.begin(), ids.end(), [&](int i, int j) {
            return persons[i] < persons[j];
        });
        cout << "after sorting" << endl;
        for (int id : ids) {
            cout << id << ", ";
        }
        cout << endl;

        vector<int> res(n);
        int accu_sum = 0;
        auto iter = diff.begin();

        // 遍历person同时遍历accumulate diff
        for (const int &id : ids) {
            while (iter != diff.end() && iter->first <= persons[id]) {
                accu_sum += iter->second;
                ++iter;
            }
            res[id] = accu_sum;
        }

        return res;
    }
};