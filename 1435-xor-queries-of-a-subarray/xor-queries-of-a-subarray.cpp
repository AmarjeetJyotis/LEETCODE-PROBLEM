class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> pref(n); // Prefix XOR array

        // Compute prefix XOR array
        pref[0] = arr[0];
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] ^ arr[i];
        }

        vector<int> ans(queries.size());
        
        // Process queries
        for(int i = 0; i < queries.size(); i++) {
            int a = queries[i][0];
            int b = queries[i][1];

            if (a == 0) ans[i] = pref[b];  // Ifstarting 0, directly take pref[b]
            else ans[i] = pref[b] ^ pref[a - 1]; // XOR range [a, b]
        }

        return ans;
    }
};