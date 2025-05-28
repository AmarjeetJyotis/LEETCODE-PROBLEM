// class Solution {
// public:
// const int mod=1e9+7;
// int memo[1001][1001];
// long long solve(int n,int k){
//     if(n==k) return 1;
//     if(n==0 || k==0) return 0;

//     if(memo[n][k]!=-1) return memo[n][k];

//     return memo[n][k]=(solve(n-1,k-1)%mod+(n-1)*solve(n-1,k)%mod)%mod;

// }
//     int rearrangeSticks(int n, int k) {
//         memset(memo,-1,sizeof(memo));

//         return solve(n,k);
     
        
//     }
// };





#include <vector>

class Solution {
public:
    const int mod = 1e9 + 7;

    int rearrangeSticks(int n, int k) {
        // Create a 2D array to store the dp values
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        // Base cases
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;  // 0 ways to arrange i sticks with 0 visible sticks
        }
        for (int i = 0; i <= k; i++) {
            dp[i][i] = 1;  // 1 way to arrange i sticks with i visible sticks
        }

        // Fill the dp array using the recurrence relation
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = (dp[i - 1][j - 1] + ((long long)(i - 1) * dp[i - 1][j]) % mod) % mod;
            }
        }

        // Return the final answer from the dp table
        return dp[n][k];
    }
};