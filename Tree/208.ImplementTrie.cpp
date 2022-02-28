#include "../Common.h"


class Trie {
public:
    Trie() {
    }

    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            c -= 'a';
            if (!node->next[c])
                node->next[c] = new Trie();

            node = node->next[c];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for (char c: word) {
            c -= 'a';
            if (!node->next[c])
                return false;

            node = node->next[c];
        }
        return node->isWord;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char c: prefix) {
            c -= 'a';
            if (!node->next[c])
                return false;

            node = node->next[c];
        }
        return true;
    }

private:
    Trie* next[26] = {};
    bool isWord = false;
};
