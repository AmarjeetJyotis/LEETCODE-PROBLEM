class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());               // 1. sort
        int i = 0, n = nums.size(), groups = 0;

        while (i < n) {                               // 3. process one group
            int limit = nums[i] + k;                  //   smallest + k
            i = upper_bound(nums.begin() + i,         //   first index > limit
                            nums.end(),
                            limit) - nums.begin();
            ++groups;                                 //   one group formed
        }
        return groups;                                // 4. answer
    }
};