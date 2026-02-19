// class Solution {
// public:
//     vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        
//     }
// };








class TrieNode {
public:
    unordered_map<string, TrieNode*> children;
    bool deleted = false;
};

class Solution {
    unordered_map<string, int> serialCount;

    // Build the Trie
    void insert(TrieNode* root, vector<string>& path) {
        TrieNode* node = root;
        for (string& folder : path) {
            if (!node->children.count(folder)) {
                node->children[folder] = new TrieNode();
            }
            node = node->children[folder];
        }
    }

    // Serialize subtree
    string serialize(TrieNode* node) {
        if (node->children.empty()) return "";

        vector<pair<string, string>> serials;
        for (auto& [name, child] : node->children) {
            serials.emplace_back(name, serialize(child));
        }

        sort(serials.begin(), serials.end());
        string s;
        for (auto& [name, sub] : serials) {
            s += "(" + name + sub + ")";
        }

        serialCount[s]++;
        return s;
    }

    // Mark duplicates
    string mark(TrieNode* node) {
        if (node->children.empty()) return "";

        vector<pair<string, string>> serials;
        for (auto& [name, child] : node->children) {
            serials.emplace_back(name, mark(child));
        }

        sort(serials.begin(), serials.end());
        string s;
        for (auto& [name, sub] : serials) {
            s += "(" + name + sub + ")";
        }

        if (serialCount[s] > 1) {
            node->deleted = true;
        }

        return s;
    }

    // Collect all remaining paths
    void collect(TrieNode* node, vector<string>& path, vector<vector<string>>& res) {
        for (auto& [name, child] : node->children) {
            if (!child->deleted) {
                path.push_back(name);
                res.push_back(path);
                collect(child, path, res);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        TrieNode* root = new TrieNode();

        // Step 1: Build Trie
        for (auto& path : paths) {
            insert(root, path);
        }

        // Step 2: Serialize to find duplicates
        serialize(root);

        // Step 3: Mark duplicates
        mark(root);

        // Step 4: DFS to collect results
        vector<vector<string>> result;
        vector<string> current;
        collect(root, current, result);

        return result;
    }
};
