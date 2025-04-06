class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        // Precompute prefix sums
        vector<int> presum(n + 1, 0);
        for (int i = 0; i < n; ++i)
            presum[i + 1] = presum[i] + arr[i];

        int left = 0, right = arr[n - 1];
        int result = 0;
        int minDiff = INT_MAX;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Find index where arr[i] > mid
            int idx = upper_bound(arr.begin(), arr.end(), mid) - arr.begin();
            int currSum = presum[idx] + (n - idx) * mid;
            int diff = abs(currSum - target);

            if (diff < minDiff || (diff == minDiff && mid < result)) {
                minDiff = diff;
                result = mid;
            }

            if (currSum < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};