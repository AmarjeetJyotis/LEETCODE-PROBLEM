class Solution {
public:
    // Function to compute the sum of prime factors of n
    int factorSum(int n) {
        int ans = 0;
        int divisor = 2;
        while (n > 1) {
            if (n % divisor == 0) {
                ans += divisor;
                n /= divisor;
            } else {
                divisor++;
            }
        }
        return ans;
    }

    int smallestValue(int n) {
        while (true) {
            int sum = factorSum(n);
            if (n == sum) break;
            n = sum;
        }
        return n;
    }
};