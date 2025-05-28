class Solution {
public:
int MOD=1e9+7;
int rev(int x){
    int ans=0;
    while(x>0){
        ans=ans*10+x%10;
        x/=10;
    }
    return ans;
}
    int countNicePairs(vector<int>& nums) {
        int n=nums.size();
        int c=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            
                int x=nums[i]-rev(nums[i]);
                c=(c+mp[x])%MOD;
                mp[x]++;

            
        }
        return c;

    }
};