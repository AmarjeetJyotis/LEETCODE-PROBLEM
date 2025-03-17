#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ans = 0;
        int rows = grid.size();
        int cols = grid[0].size();

 
        for (int row = 0; row < rows; row++) {
            for (int col = 1; col < cols; col++) {
                grid[row][col] += grid[row][col - 1];
            }
        }


        for (int col = 0; col < cols; col++) {
            int sum = 0;
            for (int row = 0; row < rows; row++) {
                sum += grid[row][col];
                if (sum <= k) {
                    ans += 1;
                }
            }
        }

        return ans;
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();