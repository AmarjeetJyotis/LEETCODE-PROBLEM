class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int res = abs(nums[0] - nums.back());
        for (int i = 1, n = nums.size(); i < n; ++i)
            res = max(res, abs(nums[i] - nums[i-1]));
        return res;
    }
};