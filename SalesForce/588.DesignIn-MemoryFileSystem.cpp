#include "../Common.h"


struct fileNode {
    unordered_map<string, fileNode*> next;
    bool isFile;
    string content;
    fileNode() : isFile(false), content("") {}
};


class FileSystem {
public:
    FileSystem() {
        root = new fileNode();
    }
    
    vector<string> ls(string path) {
        fileNode *cur = cd(path);
        if (cur->isFile)
            return { path.substr(path.find_last_of('/') + 1) };
        
        vector<string> res;
        for (auto &p : cur->next) {
            res.push_back(p.first);
        }
        
        sort(res.begin(), res.end());
        return res;
    }
    
    void mkdir(string path) {
        fileNode *cur = cd(path);
    }
    
    void addContentToFile(string filePath, string content) {
        fileNode *cur = cd(filePath);
        cur->content += content;
        cur->isFile = true;
    }
    
    string readContentFromFile(string filePath) {
        fileNode *cur = cd(filePath);
        return cur->content;
    }
    
private:
    fileNode *root;
    fileNode *cd(string path) {
        fileNode *cur = root;
        stringstream s(path);
        string dir;
        while (getline(s, dir, '/')) {
            if (dir.size()) {
                if (cur->next[dir] == nullptr) {
                    cur->next[dir] = new fileNode();
                }
                cur = cur->next[dir];
            }
        }
        return cur;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */