class Solution {
public:
    bool splitArraySameAverage(vector<int>& a) {
        int n = a.size(), tot = accumulate(a.begin(), a.end(), 0);
        int M = tot / 2 + 1, N = n / 2 + 1;
        vector <bool> vis(M * N, 0);
        vector <int> q; q.reserve(N/2 * M);
        int cnt = 0;
        for (int i = 1; i <= n / 2; i++) { // n / 2
            if ((tot * i) % n) 
                continue ;
            if (int next = i * M + tot * i / n; 
                vis[next] == 0) {
                vis[next] = 1;
                q.push_back(next); 
                cnt++;
                if (cnt > 5)
                    break;
            }
        }
        for (int i = 0; i < n; i++) {
            int nn = q.size();
            for (int j = 0; j < nn; j++) { // 10^4 * 30 / 2
                int next = q[j] - a[i] - M;
                if (next == 0) 
                    return true;
                if (next > 0 && vis[next] == 0) {
                    vis[next] = 1;
                    q.push_back(next); 
                }
            }
        }
        return false;
    }
};