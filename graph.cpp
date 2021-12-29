#include <algorithm>
#include <iterator>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <stack>


using namespace std;

// BFS, DFS

/**
 * @brief BFS, starting point, queue
 * 
 */
// Definition for a Node.
// class Node {
// public:
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution133 {
public:
    Node* cloneGraph(Node* node) {
        // edge case
        if (node == NULL)
            return NULL;

        queue<Node*> tasks;
        unordered_map<Node*, Node*> nodes_ {};

        // clone the head node in the original graph, new node node_
        Node* node_ = new Node(node->val, {});
        // construct lookup table
        nodes_.emplace(std::make_pair(node, node_));
        tasks.push(node);

        while (!tasks.empty()) {
            Node* cur = tasks.front();
            tasks.pop();

            for (auto neighbor : cur->neighbors) {
                // if not visited
                if (nodes_.find(neighbor) == nodes_.end()) {
                    nodes_[neighbor] = new Node(neighbor->val, {});
                    tasks.push(neighbor);
                }
                // if visited
                // clone edges
                nodes_[cur]->neighbors.push_back(nodes_[neighbor]);
            }
        }
        return node_;
    }
};


class Solution138 {
    public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        unordered_map<Node *, Node *> mapping {};
        Node *cur = head;

        // bsf with iter
        while (cur) {
            mapping[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;
        while (cur) {
            mapping[cur] -> next = mapping[cur->next];
            mapping[cur] -> random = mapping[cur->random];
            cur = cur->next;
        }

        return mapping[head];
    }
};


class Solution46 {
    vector<vector<int>> res;

public:
    vector<vector<int>> permute(vector<int>& nums) {
        // edge case
        if (nums.size() == 0) {
            return res;
        }

        vector<int> v;
        helper(res, v, nums);
        return res;
    }

private:
    void helper(vector<vector<int>> &res, 
                vector<int>& v,
                vector<int>& nums) {

        if (v.size() == nums.size()) {
            res.emplace_back(v);
            return;
        }

        for (int num : nums) {
            cout << "dfs nu m: " << num << endl;
            if (std::find(v.begin(), v.end(), num) == v.end()) {
                v.push_back(num);
                helper(res, v, nums);
                v.pop_back();
            }
        }
    }
};


class Solution78 {
    vector<vector<int>> res;

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        helper(res, v, nums, 0);
        return res;
    }

private:
    void helper(vector<vector<int>> &res,
                vector<int> &v,
                vector<int> &nums,
                int p) {
        res.emplace_back(v);
        for (int i = p; i < nums.size(); i++) {
            v.push_back(nums.at(i));
            helper(res, v, nums, i + 1);
            v.pop_back();
        }
    }
};


class Solution90 {
    vector<vector<int>> res;
    vector<int> v;

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        helper(res, v, nums, 0);
        return res;
    }

private:
    void helper(vector<vector<int>> &res,
                vector<int> &v,
                vector<int> &nums,
                int p) {
        res.emplace_back(v);
        for (int i = p; i < nums.size(); i++) {
            if (i == p || nums[i] != nums[i - 1]) {
                v.push_back(nums[i]);
                helper(res, v, nums, i + 1);
                v.pop_back();
            }
        }
    }
};


class Solution51 {
public:
    vector<vector<string>> res;
    vector<int> v;

    /**
     * @brief solving problem of placing n queens on an n x n chessboard such * * that no two queens attack each other.
     * 
     * @param n : int
        number of queens
     * @return vector<vector<string>> 
     */
    vector<vector<string>> solveNQueens(int n) {
        if (n <= 0) {
            return res;
        }

        search(res, v, n);
        return res;
    }

private:
    void search(vector<vector<string>> &res,
                vector<int> &v,
                int n) {
        int i = v.size();
        cout << "currnt processing row: " << i << endl;
        if (i == n) {
            res.push_back(dispChessBoard(v));
            return ;
        }

        for (int j = 0; j < n; j++) {
            if (isValid(v, j)) {
                v.push_back(j);
                search(res, v, n);
                v.pop_back();
            }
        }
    }

    bool isValid(vector<int> &mtrx, int col) {
        int row = mtrx.size();
        for (int i = 0; i < row; i++) {
            if (mtrx.at(i) == col ||            // 
                row + col == i + mtrx.at(i) ||  // diagonal term
                row - col == i - mtrx.at(i)) {  // diagonal term
                return false;
            }
        }

        return true;
    }

    vector<string> dispChessBoard(vector<int> mtrx) {
        vector<string> board;
        for (int i = 0; i < mtrx.size(); i++) {
            string s(mtrx.size(), '.');
            for (int j = 0; j < mtrx.size(); j++) {
                if (j == mtrx.at(i)) {
                    s[j] = 'Q';
                }

            }
            board.push_back(s);
        }
        return board;
    }
}; 


class Solution131 {
    vector<vector<string>> res;
    vector<string> v;

public:
    vector<vector<string>> partition(string s) {
        helper(s, v, res, 0);
        return res;
    }

private:
    void helper(string s,
                vector<string> &v,
                vector<vector<string>> &res, 
                int p) {

        if (p == s.size()) {
            res.emplace_back(v);
        }

        string substr = "";
        for (int i = p; i < s.size(); i++) {
            substr += s.at(i);
            if (isPalindrome(substr)) {
                v.push_back(substr);
                helper(s, v, res, i + 1);
                v.pop_back();
            }
        }
    }

    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if (s.at(i) != s.at(j)) {
                return false;
            }
        }

        return true;
    }
};


class Solution39 {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> v;

    void helper(vector<int> &candidates, 
                int target, 
                int p) {
        if (target == 0) {
            res.push_back(v); 
            return;
        }

        for (int i = p; i < candidates.size() && target >= candidates[i]; i++) {
            v.push_back(candidates[i]);
            helper(candidates, target - candidates[i], i);
            v.pop_back();
        }
    }
};


class Solution40 {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> v;

    void helper(vector<int> &candidates, 
                int target, 
                int p) {
        if (target == 0) {
            res.push_back(v); 
            return;
        }

        for (int i = p; i < candidates.size() && target >= candidates[i]; i++) {
            if (i == p || candidates[i] != candidates[i - 1]) {
                v.push_back(candidates[i]);
                helper(candidates, target - candidates[i], i + 1);
                v.pop_back();
            }
        }
    }
};


class Solution127 {

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        copy(wordList.begin(), wordList.end(), inserter(graph, graph.begin()));
        addTask(beginWord);
        int dist = 2;
        while (!taskQueue.empty()) {
            int num = taskQueue.size();
            for (int i = 0; i < num; i++) {
                string task = taskQueue.front();
                taskQueue.pop();
                if (task == endWord) { 
                    return dist;
                }
                addTask(task);
            }
            dist++;
        }
        return 0;
    }

private:
    unordered_set<string> graph;
    queue<string> taskQueue;

    void addTask(string word) {
        graph.erase(word);
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            for (int j = 0; j < 26; j++) {
                word[i] = 'a' + j;
                if (graph.find(word) != graph.end()) {
                    taskQueue.push(word);
                    graph.erase(word);
                }
            }
            word[i] = c;
        }
    }
};


int main(int argc, char* argv[]) {
    vector<int> test {-1,0,3,5,9,12};
    Solution46().permute(test);
}
