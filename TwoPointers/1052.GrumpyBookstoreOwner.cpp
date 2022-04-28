#include "../Common.h"


class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        assert(customers.size() == grumpy.size());
        int n = customers.size();

        // 计算没有滑窗逆天改命的情况下的满意度之和
        int sum = 0;
        for (int i = 0; i < n; ++i)
            if (grumpy[i]==0)
                sum += customers[i];

        // 计算有滑窗逆天改命的情况下的满意度之和
        int i = minutes;
        while (i-- > 0) {
            if (grumpy[i] == 1)
                sum += customers[i];
        }
        int res = sum;
        cout << "res = " << res << endl;

        for (int i = 1; i < n - minutes; ++i) {
            if (grumpy[i - 1] == 1)
                sum -= customers[i - 1];

            sum += grumpy[i + minutes] == 1 ? customers[i + minutes] : 0;
            res = max(res, sum);
        }

        return res;
    }
};