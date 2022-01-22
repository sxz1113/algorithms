#include "Common.h"


// 2 pointers
class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0, 
            i = 0,
            j = height.size() - 1,
            h;

        while(i < j) {
            h = min(height[i], height[j]);
            area = max(area, (j - i) * h);
            while (height[i] <= h && i < j)
                ++i;

            while (height[j] <= h && i < j)
                --j;
        }

        return area;
    }
};