#include <bits/stdc++.h>
const int MOD = 1e9 + 7, N = 1e5 + 1;
using namespace std;

class Solution {
    public:
        long long dp[N];
        long long nextIndex(vector<pair<long long, pair<long long, long long>>> &a, long long ind) {
            long long lo = ind, hi = a.size() - 1, ans = 1e9;
            while(lo <= hi) {
                long long mid = (lo + hi) / 2;
                if (a[mid].first >= a[ind].second.first) {
                    ans = min(ans, mid);
                    hi = mid - 1;
                }
                else {
                    lo = mid + 1;
                }
            }
            return ans;
        }
        long long func(long long i, vector<pair<long long, pair<long long, long long>>> &a) {
            if (i >= a.size()) return 0;
            if (dp[i] != -1) return dp[i];
            long long take = 0, nottake = 0;
            take = a[i].second.second + func(nextIndex(a, i), a);
            nottake = func(i + 1, a);
            return dp[i] = max(take, nottake);
        }
        int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
            memset(dp, -1, sizeof(dp));
            vector<pair<long long, pair<long long, long long>>> a;
            for (int i = 0; i < startTime.size(); i++) {
                a.push_back({startTime[i], {endTime[i], profit[i]}});
            }
            sort(a.begin(), a.end());
            return func(0, a);
        }
    };

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();