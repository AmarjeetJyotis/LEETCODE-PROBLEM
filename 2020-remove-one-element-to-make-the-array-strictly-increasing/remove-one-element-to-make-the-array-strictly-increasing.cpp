class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int cnt = 0;
        for(int i = 1, n = nums.size(); i < n; ++i){
            if(nums[i] <= nums[i - 1]){
                if(++cnt > 1) return false;
                if(i > 1 && nums[i] <= nums[i - 2]) nums[i] = nums[i - 1];
            }
        }
        return true;
    }
};