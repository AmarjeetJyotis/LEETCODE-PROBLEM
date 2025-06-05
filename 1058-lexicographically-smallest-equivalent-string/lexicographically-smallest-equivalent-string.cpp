class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26);
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }

        // Union Find
        function<int(int)> find = [&](int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };

        // Union
        auto unite = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                if (rootX < rootY) {
                    parent[rootY] = rootX;
                } else {
                    parent[rootX] = rootY;
                }
            }
        };

        // Build the union find data structure
        for (int i = 0; i < s1.size(); i++) {
            unite(s1[i] - 'a', s2[i] - 'a');
        }

        // Find the smallest equivalent string
        string result;
        for (char c : baseStr) {
            result += 'a' + find(c - 'a');
        }

        return result;
    }
};