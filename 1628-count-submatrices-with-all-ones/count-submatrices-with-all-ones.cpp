class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> height(n, 0);
        long long ans = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                height[j] = mat[i][j] ? height[j] + 1 : 0;
            }
            vector<pair<int, int>> st;
            long long cur = 0;
            for (int h : height){
                int cnt = 1;
                while (!st.empty() && st.back().first >= h){
                    cur -= 1LL * st.back().first * st.back().second;
                    cnt += st.back().second;
                    st.pop_back();
                }
                cur += 1LL * h * cnt;
                st.push_back({h, cnt});
                ans += cur;
            }
        }
        return (int)ans;
    }
};