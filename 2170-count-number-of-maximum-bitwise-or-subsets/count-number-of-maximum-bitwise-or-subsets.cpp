class Solution {
public:
    int solve(int i, vector<int>& nums, int maxi, int curr_or){
        if(i >= nums.size()){
            return curr_or == maxi ? 1 : 0;
        }

        int take = solve(i + 1, nums, maxi, curr_or | nums[i]);
        int notake = solve(i + 1, nums, maxi, curr_or);

        return take + notake;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0;
        for(int num : nums) maxi |= num;
        return solve(0, nums, maxi, 0);      
    }
};