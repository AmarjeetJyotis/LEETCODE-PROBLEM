class Solution {
public:
int solve(vector<int> &nums,int x){
    int i,n=nums.size(),cnt=0,ans=0;

    for(i=0;i<n;i++){
        if(nums[i]<=x){
            cnt++;
            ans+=cnt;
        }
        else{
            cnt=0;
        }
    }
    return ans;
}
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int a=solve(nums,right);
        int b=solve(nums,left-1);

        return a-b;
    }
};