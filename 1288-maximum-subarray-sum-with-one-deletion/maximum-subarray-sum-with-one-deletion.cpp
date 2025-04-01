class Solution {
public:
    int maximumSum(vector<int>& arr) {
        vector<int> left(arr.size());
        vector<int> right(arr.size());
        int sum=0, result=INT_MIN;

        for(int i=0; i<arr.size(); i++) {
            sum = max(sum+arr[i], arr[i]);
            result = max(result, sum);
            left[i] = sum;
        }

        sum = 0;

        for(int i=arr.size()-1; i>=0; i--) {
            sum = max(sum+arr[i], arr[i]);
            right[i] = sum;
        }

        for(int i=0; i+2<arr.size(); i++) {
            result = max(result, left[i]+right[i+2]);
        }

        return result;
    }
};