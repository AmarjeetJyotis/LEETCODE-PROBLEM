class Solution {

public:
    int countSubIslands(const vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        const int R = grid2.size();
        const int C = grid2[0].size();
        int subs = 0;
        std::queue<std::pair<int, int>> island;
        constexpr int offset[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {

                // Water or Visited.
                if (grid2[r][c] != 1) {
                    continue;
                }

                island.push({r, c});
                grid2[r][c] = -1;
                bool is_sub = true;
                while (!island.empty()) {
                    const std::pair<int, int> p = island.front();
                    island.pop();

                    grid2[p.first][p.second] = -1;
                    if (grid1[p.first][p.second] == 0) {
                        is_sub = false;
                    }                    

                    for (int i = 0; i < 4; ++i) {
                        const int x = p.first + offset[i][0];
                        const int y = p.second + offset[i][1];

                        if ((x) >= 0 && (y) >= 0 && (x) < R && (y) < C) {
                            if (1 == grid2[x][y]) {
                                island.push({x, y});
                                grid2[x][y] = -1;
                            }  
                        }
                    }
                

                } // End island exploration.
                if (is_sub) {
                    ++subs;
                }
            }
        }

        return subs;
    }
};