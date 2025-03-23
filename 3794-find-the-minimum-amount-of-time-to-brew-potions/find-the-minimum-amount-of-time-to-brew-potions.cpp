class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        vector<vector<long long>> v(m, vector<long long>(n + 1));

        v[0][0] = 0;
        for(int i = 1; i <= n; i++) {
            v[0][i] = v[0][i-1] + skill[i - 1] * mana[0];
        }


        for(int i = 1; i < m; i++) {
            
            v[i][n] = v[i - 1][n] + mana[i] * skill[n - 1];
            for(int j = n - 1; j >= 0; j--) {
                v[i][j] = max(v[i - 1][j + 1], v[i][j + 1] - (skill[j] * mana[i]));
            }

            for(int j = 1; j <= n; j++) {
                v[i][j] = v[i][j - 1] + (skill[j - 1] * mana[i]);
            }
        }
        
        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j <= n; j++) {
        //         cout << v[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return v[m - 1][n];
    }
};