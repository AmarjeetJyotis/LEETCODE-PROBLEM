class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;
        vector<vector<int>> minTime(m, vector<int>(n, INT_MAX));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        minTime[0][0] = 0;
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int currTime = curr[0], row = curr[1], col = curr[2];
            if (row == m - 1 && col == n - 1) return currTime;
            if(visited[row][col]) continue;
            visited[row][col] = true;
            for (auto& dir : directions) {
                int Nrow = row + dir[0];
                int Ncol = col + dir[1];
                if(Nrow<0 || Nrow>=m || Ncol<0 || Ncol>=n || visited[Nrow][Ncol]) continue;
                if(grid[Nrow][Ncol] <= currTime+1){
                    pq.push({currTime+1, Nrow, Ncol});
                    minTime[Nrow][Ncol] = currTime+1;
                } else if((grid[Nrow][Ncol]-currTime)%2 == 0){
                    pq.push({grid[Nrow][Ncol]+1, Nrow, Ncol});
                    minTime[Nrow][Ncol] = grid[Nrow][Ncol] + 1;
                }else{
                    pq.push({grid[Nrow][Ncol], Nrow, Ncol});
                    minTime[Nrow][Ncol] = grid[Nrow][Ncol];
                }
            }
        }
        return -1;
    }
};