class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));   
        dp=grid;
        for(int i=n-2;i>=0;i--){
           for(int j=1;j<m-1;j++){
              if(grid[i][j]==1 && grid[i+1][j]==1){
                  dp[i][j]=1+min(dp[i+1][j-1],dp[i+1][j+1]);
              }
           }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // cout<<dp[i][j]<<" ";
                ans+=(max(0,dp[i][j]-1));
            }
            // cout<<endl;
        }
        dp=grid;
        for(int i=1;i<n;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==1 && grid[i-1][j]==1){
                    dp[i][j]=1+min(dp[i-1][j-1],dp[i-1][j+1]);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //  cout<<dp[i][j]<<" ";
                ans+=(max(0,dp[i][j]-1));
            }
            // cout<<endl;
        }
        return ans;
    }
};