class Solution {
public:
    // Recursive approach (inefficient)
    int solveRE(int K, int N) {
        if (N <= 1) return N;  // If 0 or 1 floor, we need at most N drops
        if (K == 1) return N;  // With one egg, we drop from every floor

        int ans = INT_MAX;
        for (int i = 1; i <= N; i++) {
            int broken = solveRE(K - 1, i - 1); // Egg breaks -> Check below
            int unbroken = solveRE(K, N - i);   // Egg survives -> Check above
            int worst = 1 + max(broken, unbroken); // Worst-case scenario
            ans = min(ans, worst);
        }
        return ans;
    }

    // Memoized approach (top-down dynamic programming)
    int solveME(vector<vector<int>>& dp, int K, int N) {
        if (N <= 1) return N;  // Base case: If 0 or 1 floor, N drops
        if (K == 1) return N;  // Base case: With one egg, N drops

        if (dp[K][N] != -1) return dp[K][N];  // Return memoized result

        int ans = INT_MAX;
        for (int i = 1; i <= N; i++) {
            int broken = solveME(dp, K - 1, i - 1); // Egg breaks
            int unbroken = solveME(dp, K, N - i);   // Egg doesn't break
            int worst = 1 + max(broken, unbroken);  // Worst-case scenario
            ans = min(ans, worst);  // Find minimum number of drops
        }

        return dp[K][N] = ans;  // Memoize the result
    }

    // Binary Search optimization with memoization
    int solve_Binary_ME(vector<vector<int>>& dp, int K, int N) {
        if (N <= 1) return N;
        if (K == 1) return N;

        if (dp[K][N] != -1) return dp[K][N];

        int ans = INT_MAX;
        int l = 1, r = N;

        while (l <= r) {
            int mid = (l + r) / 2;  // Find the middle floor

            int broken = solve_Binary_ME(dp, K - 1, mid - 1);  // Egg breaks
            int unbroken = solve_Binary_ME(dp, K, N - mid);    // Egg doesn't break

            int worst = 1 + max(broken, unbroken);  // Worst-case scenario
            ans = min(ans, worst);  // Minimize the number of drops

            if (broken > unbroken) {
                r = mid - 1;  // Move downwards
            } else {
                l = mid + 1;  // Move upwards
            }
        }

        return dp[K][N] = ans;  // Memoize the result
    }

    // Main function to solve the problem
    int twoEggDrop(int n) {
        vector<vector<int>> dp(3, vector<int>(n + 1, -1));  // DP table
        return solve_Binary_ME(dp, 2, n);  // Call the optimized function with 2 eggs
    }
};