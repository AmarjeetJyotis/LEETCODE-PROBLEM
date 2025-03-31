class Solution {
public:
    vector<int> gridIllumination(const int n, const vector<vector<int>>& lamps,
                                 const vector<vector<int>>& queries) {
        [[assume((1 <= n && n <= 1'000'000'000))]];
        [[assume((0 <= lamps.size() && lamps.size() <= 20000))]];
        [[assume((0 <= queries.size() && queries.size() <= 20000))]];
        // Hash maps to track illuminated rows, columns, and diagonals
        unordered_map<unsigned int, unsigned int> rowCount, colCount,
            diag1Count, diag2Count;
        // Hash set to store active lamp positions
        unordered_set<unsigned int> lampSet;

        // Preprocess lamps
        for (const auto& lamp : lamps) {
            const int r = lamp[0], c = lamp[1];
            const unsigned int key =
                static_cast<unsigned int>(r) * n + c; // Unique key for (r, c)
            if (lampSet.insert(key)
                    .second) { // If the lamp is not already in the set
                rowCount[r]++;
                colCount[c]++;
                diag1Count[r + c]++;
                diag2Count[r - c]++;
            }
        }

        // Directions for 8 adjacent cells
        constexpr int directions[9][2] = {{-1, -1}, {-1, 0}, {-1, 1},
                                          {0, -1},  {0, 0},  {0, 1},
                                          {1, -1},  {1, 0},  {1, 1}};

        vector<int> ans;
        for (const auto& query : queries) {
            const int r = query[0], c = query[1];
            const bool illuminated =
                (rowCount[r] > 0 || colCount[c] > 0 || diag1Count[r + c] > 0 ||
                 diag2Count[r - c] > 0);
            ans.emplace_back(illuminated ? 1 : 0);

            // Turn off the lamp at (r, c) and its 8 adjacent lamps
            for (const auto& dir : directions) {
                const int nr = r + dir[0], nc = c + dir[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    const unsigned int key =
                        static_cast<unsigned int>(nr) * n + nc;
                    if (lampSet.erase(key)) { // If the lamp exists, turn it off
                        rowCount[nr]--;
                        colCount[nc]--;
                        diag1Count[nr + nc]--;
                        diag2Count[nr - nc]--;
                    }
                }
            }
        }

        return ans;
    }
};