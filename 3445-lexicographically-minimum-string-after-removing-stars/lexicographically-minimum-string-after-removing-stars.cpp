class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<stack<int>> freq(26); // Stacks for each character 'a' to 'z'

        // First pass: mark characters to be removed
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                // Remove the smallest available character
                for (int j = 0; j < 26; j++) {
                    if (!freq[j].empty()) {
                        s[freq[j].top()] = '*'; // Mark for removal
                        freq[j].pop();
                        break;
                    }
                }
            } else {
                freq[s[i] - 'a'].push(i); // Store index of the character
            }
        }

        // Second pass: build result without '*'
        string result = "";
        for (int i = 0; i < n; i++) {
            if (s[i] != '*') {
                result += s[i];
            }
        }

        return result;
    }
};