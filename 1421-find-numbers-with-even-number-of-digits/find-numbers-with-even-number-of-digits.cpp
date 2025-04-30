class Solution 
{
public:
    int findNumbers(vector<int>& nums) 
    {
        int count = 0;

        // Step 1: Loop through each number
        for(int i = 0; i < nums.size(); i++) 
        {
            // Step 2: Convert to string
            string s = to_string(nums[i]);

            // Step 3: Check if length is even
            if(s.length() % 2 == 0) 
            {
                // Step 4: Increment count
                count++; 
            }
        }

        // Step 5: Return result
        return count;
    }
};