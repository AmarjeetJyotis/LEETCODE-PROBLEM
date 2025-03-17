class Solution {
public:
    int solve(vector<int>& nums, int k, int mid) {
        int stud = 1;
        int pages = 0;

        for (int i : nums) {
            if (pages + i <= mid) {
                pages += i;
            } else {
                stud++;
                pages = i;
            }
        }

        return stud;
    }

    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        int ans;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int stud = solve(nums, k, mid);

            if (stud <= k) {
                ans = mid;
                right = mid - 1;
            } else if (stud > k) {
                left = mid + 1;
            }
        }
        return ans;
    }
};