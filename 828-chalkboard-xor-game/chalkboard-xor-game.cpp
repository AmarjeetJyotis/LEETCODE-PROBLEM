class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int storNum = 0;
        for (int num : nums) {
            storNum ^= num;
        }
        return storNum == 0 || nums.size() % 2 == 0;
    }
};