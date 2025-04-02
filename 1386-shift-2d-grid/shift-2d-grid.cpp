class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        // support variables
        int w = grid[0].size(), h = grid.size(), tot = h * w;
        div_t target;
        // fixing k if needed
        k %= tot;
        // edge case: no need to loop
        if (!k) return grid;
        for (int i = 0, lmt = gcd(tot, k), tmp, j; i < lmt; i++) {
            j = i;
            target = div(j, w);
            tmp = grid[target.quot][target.rem];
            do {
                j += k;
                if (j >= tot) j -= tot;
                target = div(j, w);
                swap(tmp, grid[target.quot][target.rem]);
            } while (j != i);
        }
        return grid;
    }
};