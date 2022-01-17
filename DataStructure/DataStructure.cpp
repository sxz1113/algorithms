#include <algorithm>
#include <iterator>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <utility>
#include <vector>
#include <stack>


using namespace std;


class MinStack {
private:
    vector<int> stack_, min_stack;

public:
    MinStack() {
        min_stack.push_back(INT_MAX);
    }

    void push(int val) {
        stack_.push_back(val);
        min_stack.push_back(min(min_stack.back(), val));
    }
    
    void pop() {
        stack_.pop_back();
        min_stack.pop_back();
    }
    
    int top() {
        return stack_.back();
    }
    
    int getMin() {
        return min_stack.back();
    }
};


class MyQueue {
private:
    stack<int> stack1, stack2;

    void transfer() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }   
        }
    }

public:
    MyQueue() {
    }
    
    void push(int x) {
        stack1.push(x);
    }
    
    int pop() {
        transfer();
        int a = stack2.top();
        stack2.pop();
        return a;
    }
    
    int peek() {
        transfer();
        return stack2.top();
    }
    
    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int res = 0, height, h, w;
        
        // add dummy to the left end
        st.push(0);
        for (size_t i = 0; i <= heights.size(); i++) {
            int height = (i == heights.size()) ? -1 : heights[i]; 
            // if a smaller element is inserted, 
            // pop the top element on stack
            // make stack monotonously increasing
            while (!st.empty() && height <= heights[st.top()]) {
                h = heights[st.top()];
                st.pop();
                w = st.empty() ? i : i - st.top() - 1;
                res = max(res, h * w);
            }
            st.push(i);
        }
        
        return res;
    }
};


/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution654 {
private:
    // void printStack(stack<TreeNode *> s) {
    //     stack<TreeNode *> temp;
    //     cout << "current stack: ";
    //     while (!s.empty()) {
    //         temp.push(s.top());
    //         s.pop();
    //     }

    //     while (!temp.empty()) {
    //         TreeNode *t = temp.top();
    //         temp.pop();
    //         cout << t->val << " ";
    //         s.push(t);
    //     }

    //     cout << endl;
    // }

public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }

        stack<TreeNode *> st;
        for (size_t i = 0; i < nums.size(); i++) {
            cout << " == LOOP "  << i << ": evaluating " << nums[i] << " == " << endl;
            TreeNode *tree_node = new TreeNode(nums[i]);
            TreeNode *left = NULL;

            while (!st.empty() && st.top()->val < nums[i]) {
                left = st.top();
                st.pop();
                cout << "pop " << left->val << " out of stack" << endl;
                // printStack(st);
                // cout << endl;
            }
            tree_node->left = left;
            if (left) {
                cout << left->val << " <== " << tree_node->val << endl;
            } else {
                cout << "NULL" << " <== " << tree_node->val << endl;
            }

            if (!st.empty()) {
                st.top()->right = tree_node;
                cout << st.top()->right->val << " ==> " << tree_node->val << endl;
            }
            st.push(tree_node);
            cout << "push " << tree_node->val << " onto stack" << endl;
            // printStack(st);
            // cout << endl;
        }

        while (st.size() > 1) {
            st.pop();
        }

        return st.top();
    }
};


class LRUCache {
    size_t c;
    unordered_map<int, list<pair<int, int>>::iterator> kv;
    list<pair<int, int>> arr;

public:
    LRUCache(int capacity) : c(capacity) {
    }
    
    int get(int key) {
        auto it = kv.find(key);
        if (it == kv.end()) {
            return -1;
        }

        arr.splice(arr.begin(), arr, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = kv.find(key);
        if (it != kv.end()) {
            arr.splice(arr.begin(), arr, it->second);
            it->second->second = value;
            return;
        }

        if (kv.size() == c) {
            int k = arr.back().first;
            arr.pop_back();
            kv.erase(k);
        }

        arr.emplace_front(key, value);
        kv[key] = arr.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


class Solution128 {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s (nums.begin(), nums.end());
        int res = 0, step;
        for (int num : s) {
            cout << " == iterate " << num << " == "<< endl;
            if (s.find(num - 1) == s.end()) {
                step = 1;
                cout << "Searching sequence starting from " << num << ": " << endl;
                while (s.find(num + step) != s.end()) {
                    cout << " current step = " << step << endl;
                    step++;
                }
                res = max(res, step);
                cout << " current max sequence lenght " << res << endl;
            } else {
                cout << num << " has lower tail, continue" << endl;
                continue;
            }
        }
        return res;
    }
};


class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
    }
    
    double findMedian() {
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


class Solution79 {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board[0].size(); j++) {
                if (dfs(board, i, j, word)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> board, int i, int j, string &word) {
        // boundary condition
        if (word.empty()) {
            return true;
        }

        // stop condition, hit the boundary
        if (i < 0 || 
            i >= board.size() || 
            j < 0 || 
            j >= board[0].size() || 
            board[i][j] != word[0]) {
                return false;
        }

        display(board);
        char c = board[i][j];

        // mask
        board[i][j] = '*';
        string s = word.substr(1);
        bool ret = dfs(board, i - 1, j, s) ||
            dfs(board, i + 1, j, s) ||
            dfs(board, i, j - 1, s) ||
            dfs(board, i, j + 1, s);

        // write back
        board[i][j] = c;
        return ret;
    }

private:
    void display(vector<vector<char>> &board) {
        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board[0].size(); j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};


class Solution442 {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        /**
         * @brief Tag: Hashtable
         */

        // unordered_map<int, int> m;
        // vector<int> res;
        // for (int num : nums) {
        //     m[num]++;
        // }

        // for (auto it : m) {
        //     if (it.second > 1) {
        //         res.push_back(it.first);
        //     }
        // }
        // return res;

        /**
         * @brief specific solution: use the array its self as frequency array
         * key: 1 <= nums[i] <= n given an integer array nums of length n
         */

        vector<int> res;
        int j;
        for (int i = 0; i < nums.size(); ++i) {
            j = abs(nums[i]) - 1;
            nums[j] *= -1;
            if (nums[j] > 0) {
                res.push_back(abs(nums[i]));
            }
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> board {
        {'A', 'B', 'C', 'E'}, 
        {'S', 'F', 'C', 'S'}, 
        {'A', 'D', 'E', 'E'}
    };

    string word ("ABCCED");
    cout << Solution79().exist(board, word) << endl;
}
