using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ppii = pair<int, pii>;
using vi = vector<int>;
using vd = vector<double>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vc = vector<char>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vs = vector<string>;
using mii = map<int, int>;
using mll = map<ll, ll>;
using umii = unordered_map<int, int>;
#define pb push_back
#define MOD 1000000007
class Solution {
public:
  vll vF, vIf;
  ll powMod(ll bs, ll x) {
    ll ans = 1;
    while (x) {
      if (x % 2){
        ans = ans * bs % MOD;
      }
      bs = bs * bs % MOD;
      x /= 2;
    }
    return ans;
  }
  ll mInv(ll x) { 
    return powMod(x, MOD - 2); 
  }
  void solveF(int n) {
    vF.resize(n + 1);
    vIf.resize(n + 1);
    vF[0] = 1;
    for (int i = 1; i <= n; ++i)
      vF[i] = vF[i - 1] * i % MOD;
    vIf[n] = mInv(vF[n]);
    for (int i = n - 1; i >= 0; i--)
      vIf[i] = vIf[i + 1] * (i + 1) % MOD;
  }
  int makeStringSorted(string s) {
    int n = s.size();
    solveF(n);
    vi vP(26, 0);
    for (char i : s) vP[i - 'a']++;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      int curr = s[i] - 'a';
      for (int j = 0; j < curr; j++) {
        if (vP[j] == 0) continue;
        vP[j]--;
        ll prm = vF[n - i - 1];
        for (int j = 0; j < 26; j++){
          prm = prm * vIf[vP[j]] % MOD;
        }
        ans = (ans + prm) % MOD;
        vP[j]++;
      }
      vP[curr]--;
    }
    return ans;
  }
};