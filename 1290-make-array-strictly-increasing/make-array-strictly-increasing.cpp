class Solution {
public:
    vector<int> dp;
    int helper(int ix,vector<int>& arr1, vector<int>& arr2){
        int n=arr1.size();
        if(ix>=n){return 0;}
        if(dp[ix+1]!=-1){return dp[ix+1];}
        int res=1e9;int prev=(ix>-1)?arr1[ix]:-1;
        int cost=0;
        for(int i=ix+1;i<=n;i++){
            if(i==n||arr1[i]>prev ){
                res=min(res,cost+helper(i,arr1,arr2));
            }
            int ub=upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();
            if(ub==arr2.size()){break;}
            if(ub<arr2.size()){
                prev=arr2[ub];
                cost++;
            }
        }
        return dp[ix+1]=res;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        dp.resize(n+1,-1);
        sort(arr2.begin(),arr2.end());
        int res=helper(-1,arr1,arr2);
        if(res==1e9){return -1;}
        return res;
    }
};