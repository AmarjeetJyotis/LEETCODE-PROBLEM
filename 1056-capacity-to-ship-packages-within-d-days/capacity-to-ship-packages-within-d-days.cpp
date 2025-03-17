class Solution {
public:
    // Count how many days are needed for a given capacity
    int solve(vector<int>& weights, int days, int capacity) {
        int temp = 0;
        int day = 1; // Start from the first day
        
        for (int weight : weights) {
            if (temp + weight > capacity) {
                // Start a new day if the current load exceeds capacity
                day++;
                temp = 0;
            }
            temp += weight;
        }

        return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        int curr = right; // Initialize to the worst case (total weight)

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int temp = solve(weights, days, mid);

            if (temp <= days) { 
                curr = mid;      // Record the current valid answer
                right = mid - 1;  // Try to find a smaller valid capacity
            } else {
                left = mid + 1;   // Capacity too small, increase it
            }
        }

        return curr;
    }
};