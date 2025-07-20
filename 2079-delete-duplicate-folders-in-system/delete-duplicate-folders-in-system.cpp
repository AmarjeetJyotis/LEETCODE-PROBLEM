#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    string name; // Name of the folder
    unordered_map<string, Node*> children; // TO map the immediate subfolders to their respective Nodes
    string signature; // Holds the subree signature after the first DFS

    Node(string temp) {
        name = temp;
        signature.clear();
    }
};

class Trie {
private:
    Node* root;
    unordered_map<string, int> sigCount;

    void insert(const vector<string>& path) { // Insertion of the folders into the trie
        Node* curr = root;
        for (auto& folder : path) {
            if (curr->children.find(folder) == curr->children.end()) // If the node doesn't exist
                curr->children[folder] = new Node(folder);

            curr = curr->children[folder];
        }
    }

    string dfsSign(Node* node) {
        if (node->children.empty()) {
            node->signature.clear();
            return "";
        }

        vector<string> parts; // TO collect all the possible paths in the signature form -> [a[b[c]]] = a->b->c
        for (auto& p : node->children) {
            parts.push_back(p.first + "[" + dfsSign(p.second) + "]");
        }

        sort(parts.begin(), parts.end());

        string sig; // Combining all such paths at the current level and store it the sigCount
        for (auto& s : parts) sig += s;

        node->signature = sig; // Assign the current folder signature to the node's signature.
        sigCount[sig]++;

        return sig;
    }

    void dfsCollect(Node* node, vector<string>& path, vector<vector<string>>&answer) {
        // If the node has children and the current signature has been seen more tha once, we drop the subtree.
        if (!node->children.empty() && sigCount[node->signature] > 1) return;

        path.push_back(node->name);
        answer.push_back(path);

        // Recurse into every child. Add the node name to path and append to the answer.
        for (auto& p : node->children) dfsCollect(p.second, path, answer);

        path.pop_back();
    }
public:
    Trie() {
        root = new Node("");
    }
    vector<vector<string>> collectAnswer(vector<vector<string>>& paths) {
        // Inserting of the paths into the trie
        for (auto& path : paths) insert(path);

        // Getting each node's subtree signatur and count the signature count -> sigCount
        for (auto& p : root->children) dfsSign(p.second);

        // Walk the trie again, and if th subtree signatue has been seen before drop it and from the answer.
        vector<vector<string>> answer;
        vector<string> current;
        for (auto& p : root->children) dfsCollect(p.second, current, answer);

        return answer;
    }
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Trie trie;
        return trie.collectAnswer(paths);
    }
};