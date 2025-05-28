class Solution {
public:
    #define ll long long
    unordered_map<ll,ll>mp;

    ll hashing(vector<ll>&container,ll &last){
        ll sum=0;
        for(ll i=1;i<=8;i++){
            sum=sum*31+container[i];
        }
        return sum*31+last;
    }

    ll solve(vector<ll>&container,ll last,int &batchSize){
        ll hash=hashing(container,last);
        if(mp.find(hash)!=mp.end()){
            return mp[hash];
        }
        ll answer=0;
        for(ll i=1;i<=8;i++){
            if(container[i]){
                container[i]--;
                answer=max(answer,(last==0?1:0)+solve(container,(last+i)%batchSize,batchSize));
                container[i]++;
            }
        }
        return mp[hash]=answer;
    }

    int maxHappyGroups(int batchSize, vector<int>& groups) {
        ll n=groups.size(),count=0;mp.clear();
        vector<ll>container(9,0);
        for(auto &x:groups){
            if(x%batchSize){
                if(container[batchSize-x%batchSize]>0){
                    count++;container[batchSize-x%batchSize]--;
                }
                else{
                    container[x%batchSize]++;
                }
            }
            else{
                count++;
            }
        }
        return count+solve(container,0,batchSize);
    }
};