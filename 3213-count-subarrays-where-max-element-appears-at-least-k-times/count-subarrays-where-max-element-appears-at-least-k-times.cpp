class Solution {
public:
    long long countSubarrays(vector<int>& a, int k) {
        long long n = a.size(), s = 0, e = 0, ans = 0;
        unordered_map<long long, long long> mp;
        long long mx = *max_element(a.begin(), a.end());
        while(e < n) {
            mp[a[e]]++;
            while(mp[mx] >= k) { mp[a[s]]--; s++; }
            ans += s; e++;
        } return ans;
    }
};