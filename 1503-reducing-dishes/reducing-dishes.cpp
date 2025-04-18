class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();

        // Sort the satisfaction array to process dishes in increasing order of satisfaction
        sort(satisfaction.begin(), satisfaction.end());

        // Create a suffix array to store sums of elements from index i to the end
        int suf[n];
        suf[n-1] = satisfaction[n-1];

        // Calculate suffix sums from right to left
        for (int i = n-2; i >= 0; i--) {
            suf[i] = suf[i+1] + satisfaction[i];
        }

        // Find the pivot index where suffix sum becomes non-negative
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (suf[i] >= 0) {
                idx = i;  // First valid index with non-negative suffix sum
                break;
            }
        }

        // If all suffix sums are negative, return 0 as no satisfaction can be gained
        if (idx == -1) return 0;

        // Calculate the maximum sum of "like-time" coefficients starting from the pivot index
        int x = 1;
        int maxSum = 0;
        for (int i = idx; i < n; i++) {
            maxSum += (satisfaction[i] * x);
            x++;
        }

        // Return the maximum possible satisfaction
        return maxSum;
    }
};