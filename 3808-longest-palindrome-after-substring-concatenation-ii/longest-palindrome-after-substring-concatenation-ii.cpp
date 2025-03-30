
class Solution {
public:
    bool isPal(const string &s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }
    
    int longestPalindrome(string s, string t) {
        string calomirent = s;
        
        int n = s.size(), m = t.size();
        
        vector<int> extStartS(n, 0);
        for (int i = 0; i < n; i++) {
            int best = 0;
            for (int j = i; j < n; j++) {
                if (isPal(s, i, j))
                    best = max(best, j - i + 1);
            }
            extStartS[i] = best;
        }
        
        int maxPalS = 0;
        for (int i = 0; i < n; i++) {
            maxPalS = max(maxPalS, extStartS[i]);
        }
        
        vector<int> extStartT(m, 0);
        for (int i = 0; i < m; i++) {
            int best = 0;
            for (int j = i; j < m; j++) {
                if (isPal(t, i, j))
                    best = max(best, j - i + 1);
            }
            extStartT[i] = best;
        }
        int maxPalT = 0;
        for (int i = 0; i < m; i++) {
            maxPalT = max(maxPalT, extStartT[i]);
        }
        
        vector<int> extEndT(m, 0);
        for (int i = 0; i < m; i++) {
            int best = 0;
            for (int j = 0; j <= i; j++) {
                if (isPal(t, j, i))
                    best = max(best, i - j + 1);
            }
            extEndT[i] = best;
        }
        
        int ans = max(maxPalS, maxPalT); 
        
        string r = t;
        reverse(r.begin(), r.end());
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i] == r[j]) {
                    dp[i][j] = (i > 0 && j > 0) ? dp[i-1][j-1] + 1 : 1;
                    int L = dp[i][j]; 
                    int posS = i - L + 1;  
                    int candidate1 = 2 * L;
                    if (posS + L < n)
                        candidate1 = 2 * L + extStartS[posS + L];
                    
                    int posT = m - j - 1;  
                    int candidate2 = 2 * L;
                    if (posT > 0)
                        candidate2 = 2 * L + extEndT[posT - 1];
                    
                    int candidate = max({2 * L, candidate1, candidate2});
                    ans = max(ans, candidate);
                }
            }
        }
        
        return ans;
    }
};