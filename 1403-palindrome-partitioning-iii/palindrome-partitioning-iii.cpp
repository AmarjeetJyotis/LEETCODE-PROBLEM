class Solution {
public:
    int cost(string s, int i, int j){
        int count = 0;
        while(i<j){
            if(s[i]!=s[j]) count++;
            i++;
            j--;
        }
        return count;
    }
    int utility(string s, int i, int k, vector<vector<int>>&dp){
        if(i==s.length()) return 0;
        if(k==0) return cost(s,i,s.length()-1);

        if(dp[i][k]!=-1) return dp[i][k];
        int ans = INT_MAX;
        for(int end = i; end<s.size()-k; end++){
            int c = cost(s,i,end)+utility(s,end+1,k-1,dp);
            ans = min(ans, c);
        }
        return dp[i][k] = ans;
    }
    int palindromePartition(string s, int k) {
        vector<vector<int>>dp(s.length()+1, vector<int>(k+1,-1));
        return utility(s,0,k-1,dp);
    }
};