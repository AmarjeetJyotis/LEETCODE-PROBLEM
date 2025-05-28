class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>knw;

        for(auto i : knowledge)
        {
            knw[i[0]]=i[1];
        }
        string ans;
        for(int i =0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                int j =i+1;
                while(s[j]!=')')
                {
                    j++;
                }
                string temp = s.substr(i+1,j-i-1);;
                if(knw.find(temp)!=knw.end())
                {
                    ans+=knw[temp];
                }
                else{
                    ans+='?';
                }
                i=j;
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};