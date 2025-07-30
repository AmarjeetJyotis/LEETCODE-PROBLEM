class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // Step 1: Find the maximum element in the array
        // This is crucial because the maximum bitwise AND of any subarray
        // can never exceed the maximum element in the array
        int maxVal = *max_element(nums.begin(), nums.end());
        
        // Step 2: Find the longest consecutive sequence of maximum elements
        int maxLength = 0;  // This will store our final answer
        int currentLength = 0;  // This tracks current consecutive sequence length
        
        // Step 3: Iterate through the array to find longest sequence
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maxVal) {
                // If current element equals maximum, extend current sequence
                currentLength++;
                // Update our answer if current sequence is longer
                maxLength = max(maxLength, currentLength);
            } else {
                // If current element is not maximum, reset current sequence
                currentLength = 0;
            }
        }
        
        return maxLength;
    }
};