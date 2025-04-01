const long long MOD = 1e9 + 7;

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        
        int n = arr.size();
        long long sum = 0;


        long long curr = 0;
        long long maxSub = 0;

        for(int i = 0; i < n; i++) {
            curr += arr[i];
            maxSub = max(maxSub, curr);
            if(curr < 0) {
                curr = 0;
            }
            sum += arr[i];
        }

        curr = 0;

        long long maxSubTwo = 0;
        for(int i = 0; i < 2*n; i++) {
            curr += arr[i % n];
            maxSubTwo = max(maxSubTwo, curr);
            if(curr < 0) {
                curr = 0;
            }
        }

        if(k == 1) {
            return maxSub;
        } else if(k == 2) {
            return maxSubTwo % MOD;
        } else {
            if(sum >= 0) {
                long long val1 = ( (sum % MOD ) * ((k - 2) * 1LL % MOD) ) % MOD;
                long long val2 = maxSubTwo % MOD;
                long long finalSum = (val1 + val2) % MOD;
                return finalSum;
            } else {
                return maxSubTwo;
            }
        }

        
    }
};