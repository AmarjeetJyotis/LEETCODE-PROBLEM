class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int s = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            s = s + nums[i];
        }
        if (s % 3 == 0)
            return s;
        if (s % 3 == 1) {
            int m = s;
            for (int i = 0; i < n; i++) {
                if (nums[i] % 3 == 1 && nums[i] < m)
                    m = nums[i];
            }
            int s1 = s, s2 = s;
            for (int i = 0; i < n; i++) {
                if (nums[i] % 3 == 2 && nums[i] < s1) {
                    s2 = s1;
                    s1 = nums[i];
                } else if (nums[i] % 3 == 2 && nums[i] < s2) {
                    s2 = nums[i];
                }
            }
            m = m > (s1 + s2) ? (s1 + s2) : m;
            return s - m;
        }
        int d = s;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 3 == 2 && nums[i] < d)
                d = nums[i];
        }
        int s1 = s, s2 = s;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 3 == 1 && nums[i] < s1) {
                s2 = s1;
                s1 = nums[i];
            } else if (nums[i] % 3 == 1 && nums[i] < s2) {
                s2 = nums[i];
            }
        }
        d = d > (s1 + s2) ? (s1 + s2) : d;
        return s - d;
    }
};