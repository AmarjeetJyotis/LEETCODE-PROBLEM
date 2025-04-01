class Solution {
public:
    // int
    int longestWPI(vector<int>& hours) {
        vector<int> v;
        for(auto &i: hours){
            if(i>8)v.push_back(1);
            else v.push_back(-1);
        }
        unordered_map<int,int> mp;
        int ans = 0, sum = 0;
        mp[0] = 0;
        for(int i = 0; i < v.size(); i++){
            sum += v[i];
            if(sum>0){
                ans = max(ans,i+1);
            }else if(mp.count(sum-1)){
                ans = max(ans,i-mp[sum-1]);
            }
            if(mp.count(sum)==0){
                mp[sum] = i;
            }
        }
        return ans;
    }
};