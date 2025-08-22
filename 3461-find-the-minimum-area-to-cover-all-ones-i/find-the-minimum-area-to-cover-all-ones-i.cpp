class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        

        int n = grid.size();
        int m = grid[0].size();


        int rowmax = INT_MIN;
        int colmax = INT_MIN;
        int rowmin = INT_MAX;
        int colmin = INT_MAX;


        for(int i=0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    rowmax = max(rowmax , i);
                    rowmin = min(rowmin , i);
                    colmax = max(colmax , j);
                    colmin = min(colmin , j);
                }
            }
        }



        return (rowmax-rowmin+1)*(colmax-colmin+1);





    }
};