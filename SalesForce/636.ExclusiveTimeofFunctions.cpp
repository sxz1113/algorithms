#include "../Common.h"


class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<pair<int, int>> stk;
        const string SEP {":"},
                     ST {"start"}, 
                     ED {"end"};
        vector<int> res(n);
        // vector<int> interrupt;
        for (const string log : logs) {
            vector<string> log_info = split(log, SEP);
            // cout << "log: " << log_info[0] 
            //      << " -- " << log_info[1]
            //      << " -- " << log_info[2] << endl;

            if (log_info[1] == ST) {
                // init interrupt queue
                // if (interrupt.size() < stk.size()) {
                //     for (int i = 0; i < stk.size() - interrupt.size(); ++i) {
                //         interrupt.push_back(0);
                //     }
                // }
                stk.push(make_pair<int, int>(stoi(log_info[0]), stoi(log_info[2])));
                // cout << "interrupt queue: size = " << interrupt.size()
                //      << " stack size = " << stk.size() << endl;
            } else {
                // cout << exec.first << ": " << log_info[2] << " - " << exec.second << endl;
                // check interrupt queue
                // int wait_t = 0;
                // cout << "interrupt queue: size = " << interrupt.size()
                //      << " stack size = " << stk.size() << endl;
                
                pair<int, int>exec = stk.top();
                stk.pop();
                // if (interrupt.size() > stk.size()) {
                //     wait_t = interrupt.back();
                //     interrupt.pop_back();
                //     // cout << " wait time = " << wait_t << endl;
                // }
                
                // int exec_t = stoi(log_info[2]) - exec.second - wait_t + 1;
                int exec_t = stoi(log_info[2]) - exec.second + 1;
                res[exec.first] += exec_t;

                if (!stk.empty()) {
                    res[stk.top().first] -= exec_t;
                }
                // cout << "function " << exec.first << " exe time: " << res[exec.first] << endl;
                // for (int i = 0; i < interrupt.size(); ++i) {
                //     interrupt[i] += exec_t;
                //     // cout << interrupt[i] << " ";
                // }
                // // cout << endl;
            }
        }
        return res;
    }

private:
    vector<string> split(const string &s, const string &delimiter) {
        vector<string> res;
        size_t start = 0, end;
        while ((end = s.find(":", start)) != string::npos) {
            res.push_back(s.substr(start, end - start));
            start = end + delimiter.size();
        }
        res.push_back(s.substr(start));
        return res;
    }
};