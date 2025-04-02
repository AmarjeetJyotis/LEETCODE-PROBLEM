class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        
        vector<vector<int>>ans(2,vector<int>(n,0));

        for(int i=0;i<n;i++){
            int col = colsum[i];

            if(col == 2){
                upper--,lower--;
                ans[0][i] = ans[1][i] = 1;
            }else if(col == 1){
                if(upper>=lower){
                    upper--;
                    ans[0][i] = 1;
                }else{
                    lower--;
                    ans[1][i] = 1;
                }
            }
        }

        if(lower!=0 || upper != 0)
            return {};
        return ans;
    }
};