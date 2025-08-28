class Solution {
    void sortRightSide(vector<vector<int>>& grid){
        vector<int> nums ;
        int n = grid.size() ;
        for(int j=1 ;j<n;j++){
            int i= 0 ;
            int k = j ;
            while(k<n){
                 nums.push_back(grid[i][k]);
                 i++ ;
                 k++ ;
            }
            sort(nums.begin(),nums.end()) ;
            i=0 ;
            k= j ;
            while(k<n){
                 grid[i][k]=nums[i] ;
                 i++ ;
                 k++ ;
            }
            nums.clear() ;
        }
    }
    void sortLeftSide(vector<vector<int>> &grid){
         vector<int> nums ;
         int n = grid.size() ;
         for(int i=1 ;i<n;i++){
            int j=0 ;
            int k= i;
            while(k<n){
                nums.push_back(grid[k][j]) ;
                k++ ;
                j++ ;
            }
            sort(nums.begin(),nums.end() , greater<int>()) ;
            j=0 ;
            k= i ;
            while(k<n){
                grid[k][j]=nums[j] ;
                k++ ;
                j++ ;
            }
            nums.clear() ;
         }
    }
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
       vector<int> nums ;
       for(int i= 0 ;i<grid.size();i++){
           nums.push_back(grid[i][i]) ;
       }   
       sort(nums.begin(),nums.end(),greater<int>()) ;
       for(int i= 0 ;i<grid.size();i++){
           grid[i][i]=nums[i] ;
       }
       sortRightSide(grid) ;
       sortLeftSide(grid) ;
       return grid ;
    }
};