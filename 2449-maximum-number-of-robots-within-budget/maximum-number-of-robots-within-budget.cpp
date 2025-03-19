
class Solution {
public:
    typedef long long ll;
    int maximumRobots(vector<int>& ct, vector<int>& rc, long long budget) {
        multiset<int> ms;
        ll start=0,end=0,ans=0,n=ct.size(),s=0;
        while(end<n){
            s+=rc[end];
            ms.insert(ct[end++]);
            ll val = (*ms.rbegin())+(end-start)*s;
            while(val>budget){
                s-=rc[start];
                ms.erase(ms.find(ct[start++]));
                val =ms.empty()?0 : (*ms.rbegin())+(end-start)*s;
            }
            ans=max(ans,end-start);
        }
        return ans;
    }
};