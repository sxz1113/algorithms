#include <algorithm>
#include <locale>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <stack>
#include <numeric>

using namespace std;


class Solution704 {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }

        int start = 0;
        int end = nums.size() - 1;
        int mid;

        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (nums[mid] <= target) {
                start = mid;
            } else {
                end = mid;
            }
        }

        if (nums[start] == target) {
            return start;
        }

        if (nums[end] == target) {
            return end;
        }

        return -1;
    }
};


class Solution35 {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return 0;
        }

        int start = 0;
        int end = nums.size() - 1;
        int mid;

        // look for first num in nums that is greater than target
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (nums[mid] <= target) {
                start = mid;
            } else {
                end = mid;
            }
        }

        if (nums[start] >= target) {
            return start;
        } else if (nums[end] >= target) {
            return end;
        } else {
            return end + 1;
        }
    }
};


class Solution74 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(),
            n = matrix[0].size();

        int start = 0,
            mid,
            end = m * n - 1;

        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (matrix[mid / n][mid % n] <= target) {
                start = mid;
            } else {
                end = mid;
            }
        }

        return matrix[start / n][start % n] == target 
            || matrix[end / n][end % n] == target;
    }
};

int main(int argc, char* argv[]) {
    vector<vector<int>> test {{1, 1}};
    int solution = Solution74().searchMatrix(test, 0);
    cout << solution << endl;
}
