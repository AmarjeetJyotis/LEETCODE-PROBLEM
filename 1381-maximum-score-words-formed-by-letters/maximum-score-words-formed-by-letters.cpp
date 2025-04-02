class Solution {
public:
    unordered_map<string, int> memo; 

    int is_poss(string& s, vector<int>& freq) {
        vector<int> p(26);
        for (auto& it : s)
            p[it - 'a']++;
        for (int i = 0; i < 26; i++) {
            if (p[i] > freq[i])
                return 0;
        }
        return 1;
    }

    int fn(vector<string>& a, vector<int>& freq, vector<int>& sc, int i) {
        string st ;
        for (int f : freq)
            st += to_string(f) + ",";

        if (memo[st]) return memo[st];
        
        if (i >= a.size()) return 0;

        // Exclude the current word
        int ans = fn(a, freq, sc, i + 1);

        // Include the current word if possible
        if (is_poss(a[i], freq)) {
            int sum = 0;
            for (auto& it : a[i]) {
                freq[it - 'a']--;
                sum += sc[it - 'a'];
            }
            ans = max(ans, fn(a, freq, sc, i + 1) + sum);

            // Backtrack
            for (auto& it : a[i])
                freq[it - 'a']++;
        }
        
        return memo[st] = ans;
    }

    int maxScoreWords(vector<string>& a, vector<char>& l, vector<int>& sc) {
        vector<int> freq(26);
        for (auto& i : l)
            freq[i - 'a']++;

        return fn(a, freq, sc, 0);
    }
};