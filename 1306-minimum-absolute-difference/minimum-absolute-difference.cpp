class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int minAbsDiff = INT_MAX;
        for(int i = 0;i<nums.size()-1;i++){
            minAbsDiff = min(minAbsDiff,abs(nums[i]-nums[i+1]));
        }
        vector<vector<int>>ans;
         for(int i = 0;i<nums.size()-1;i++){
            if(abs(nums[i]-nums[i+1]) == minAbsDiff)ans.push_back({nums[i],nums[i+1]});
         }
         return ans;
    }
};