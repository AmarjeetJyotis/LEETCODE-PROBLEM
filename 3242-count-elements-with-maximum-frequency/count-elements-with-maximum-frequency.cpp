class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> mp;
        int maxFreq = 0, count = 0;

        // Count frequency of each element
        for (int num : nums) {
            mp[num]++;
            maxFreq = max(maxFreq, mp[num]);  // Track max frequency
        }

        // Count how many elements have the max frequency
        for (auto it : mp) {
            if (it.second == maxFreq) {
                count += it.second;  // Add total occurrences of that element
            }
        }

        return count;
    }
};
