#include "../Common.h"


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // BFS
        // [1,2,3,null,null,4,5]
        if (!root)
            return "";

        stringstream ss;
        queue<TreeNode* > q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (!node) {
                    ss << "null,";
                } else {
                    ss << node->val << ",";
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
        cout << ss.str() << endl;
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data.substr(0, data.size() - 1));
        cout << "deserialize: " << ss.str() << endl;
        string node_str;
        vector<TreeNode*> nodes;
        int n = 0;
        while (getline(ss, node_str, ',')) {
            cout << node_str << endl;
            if (node_str == "null") {
                nodes.push_back(nullptr);
            } else {
                nodes.push_back(new TreeNode(stoi(node_str)));
            }
            ++n;
        }

        int i = 0, j = 1;
        while (j < nodes.size()) {
            if (nodes[i]) {
                nodes[i]->left = nodes[j++];
                nodes[i]->right = nodes[j++];
            }
            ++i;
        }
        return nodes.front();
    }
};