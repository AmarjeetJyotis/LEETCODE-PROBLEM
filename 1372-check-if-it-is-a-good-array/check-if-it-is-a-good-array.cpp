class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        
        int n=nums.size();
        if(n==0)return 0;
        int gcd=nums[0];
        for(int i=1;i<n;i++){
            gcd=__gcd(gcd,nums[i]);
        }
        
    return gcd==1;        
        
    }
};