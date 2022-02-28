#include "../Common.h"


class TrieNode {
public:
    bool isVal;
    vector<TrieNode*> childNode;
    TrieNode() : isVal(false) {
        childNode = vector<TrieNode* >(26, nullptr);
    }
};


class Trie {
    TrieNode* root;
public:
    Trie(vector<string>& words) {
        root = new TrieNode();
        for (const string& word : words)
            insert(word);
    };
    void insert(const string& word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); ++i) {
            int j = word[i] - 'a';
            if (!node->childNode[j])
                node->childNode[j] = new TrieNode();

            node = node->childNode[j];
        }
        node->isVal = true;
    }
    TrieNode* getRoot() {
        return root;
    }
};


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size(),
            n = board[0].size();

        Trie* trie = new Trie(words);
        TrieNode* root = trie->getRoot();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(board, root, "", i, j);
            }
        }

        vector<string> res;
        for(auto it : matched_words)
            res.push_back(it);

        return res;
        // return vector<string>(matched_words.begin(), matched_words.end());
    }

private:
    unordered_set<string> matched_words;
    vector<int> directions {0, 1, 0, -1, 0};
    void findWords(vector<vector<char>>& board, TrieNode* root, string word, int x, int y){
        if(x<0||x>=board.size()||y<0||y>=board[0].size() || board[x][y]==' ') return;
        
        if(root->childNode[board[x][y]-'a'] != NULL){
            word=word+board[x][y];
            root=root->childNode[board[x][y]-'a']; 
            if(root->isVal) matched_words.insert(word);
            char c=board[x][y];
            board[x][y]=' ';
            findWords(board, root, word, x+1, y);
            findWords(board, root, word, x-1, y);
            findWords(board, root, word, x, y+1);
            findWords(board, root, word, x, y-1);
            board[x][y]=c;        
        }
    }
    void dfs(vector<vector<char>>& board,
             TrieNode* node,
             string word,
             int i,
             int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '*')
            return;

        int idx = board[i][j] - 'a';
        if (!node->childNode[idx])
            return;

        word += board[i][j];
        cout << "word = " << word << endl;
        node = node->childNode[idx];
        if (node->isVal)
            matched_words.insert(word);

        char c = board[i][j];
        // machted, mask used letter / char
        board[i][j] = '*';
        for (int d = 1; d < directions.size(); ++d)
            dfs(board, node, word, i + directions[d - 1], j + directions[d]);

        board[i][j] = c;
    }
};
