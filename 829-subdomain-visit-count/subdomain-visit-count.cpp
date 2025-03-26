class Solution {
public:
    vector<string> subdomainVisits(vector<string>& P) {
        unordered_map<string,int> mp;
        for(int i=0;i<P.size();i++){
            string S="";
            int cnt=0;
            for(int j=0;j<P[i].length();j++){
                if(P[i][j]==' '){
                    cnt=(stoi)(S);
                    S="";
                    string q=P[i].substr(j+1);
                    mp[q]+=cnt;
                }
                else if(P[i][j]=='.'){
                    string q=P[i].substr(j+1);
                    mp[q]+=cnt;
                }
                else S+=P[i][j];
            }
        }
         vector<string> N;
        for(auto i:mp){
            string t=to_string(i.second)+" "+i.first;
            N.push_back(t);
        }
        return N;
    }
};