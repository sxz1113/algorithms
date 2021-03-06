#include "../Common.h"


class AutocompleteSystem {
private:  
    struct Node {
        unordered_map<char, Node*> child;
        string str;
        int count;
        Node(): str(""), count(0) {}
    };
    
    Node* root;
    Node* cur;
    string s = "";
    
    struct comp {
        bool operator() (pair<string, int>& a, pair<string, int>& b) {
            return a.second < b.second || a.second == b.second && a.first > b.first;
        }
    };    
    priority_queue<pair<string, int>, vector<pair<string, int>>, comp> q;
    
    
    void insert(string& s, int times) {
        Node* cur = root;
        for (char c : s) {
            if (!cur->child.count(c)) {
                cur->child[c] = new Node();
            }
            cur = cur->child[c];
        }
        cur->count += times;
        cur->str = s;
    }
    
    void dfs(Node* temp) {
        if (temp->str != "") {q.push({temp->str, temp->count});}
        for (auto& cp : temp->child) {
            dfs(cp.second);
        }        
    }
    
    
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new Node();
        for (int i = 0; i<sentences.size(); i++) {
            insert(sentences[i], times[i]);
        }
        cur = root;
    }
    
    vector<string> input(char c) {
        q = priority_queue<pair<string, int>, vector<pair<string, int>>, comp>();
        
        if (c == '#') {
            insert(s, 1);
            s = "";
            cur = root;
            return {};
        }
        
        s+=c;
        if (cur && cur->child.count(c)) {
            cur = cur->child[c];
        } else {
            cur = nullptr;
            return {};
        }
        
        dfs(cur);
        
        vector<string> results;
        while(!q.empty() && results.size() < 3) {
            results.push_back(q.top().first);
            q.pop();
        }
        return results;
    }
};