class Solution 
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) 
    {
        // Step 1 : Initialize the Map
        int n = grid.size();
        vector<int> map(n * n + 1, 0);  
        vector<int> ans(2); 

        // Step 2: Traverse the grid and populate the map with occurrences.
        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j < n; j++) 
            {
                map[grid[i][j]]++;
            }
        }

        // Step 3: Find the repeated and missing numbers.
        for(int i = 1; i <= n * n; i++) 
        {
            if(map[i] == 2) 
            {
                ans[0] = i;  // Repeated number.
            }   
            
            if(map[i] == 0) 
            {
                ans[1] = i;  // Missing number.
            }
        }

        // Step 4: Return the result.
        return ans;
    }
};