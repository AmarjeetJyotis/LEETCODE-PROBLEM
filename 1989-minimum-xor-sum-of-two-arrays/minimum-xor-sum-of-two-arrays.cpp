class Solution {
public:
    int dp[33000]; // 2^14 = 16384, enough for n ≤ 14
    int n;

    int solve(int i, int mask, vector<int>& nums1, vector<int>& nums2) {
        if (i == n) return 0;
        if (dp[mask] != -1) return dp[mask];

        int res = 1e9;
        for (int j = 0; j < n; j++) {
            if ((mask & (1 << j)) == 0) {
                res = min(res, (nums1[i] ^ nums2[j]) + solve(i + 1, mask | (1 << j), nums1, nums2));
            }
        }
        return dp[mask] = res;
    }

    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, nums1, nums2);
    }
};