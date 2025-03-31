class Solution {
public:
    bool queryString(string s, int n) {
        unordered_set<int>st;
        int len=log2(n)+1;
        int start=0;
        int end=0;
        string temp="";
        while(end<s.length())
        {
            if(temp.length()<len)
            {
                temp.push_back(s[end]);
                int num=stoi(temp,nullptr,2);
                if(num>=1 and num<=n)
                {
                    st.insert(num);
                }
                end++;
            }
            else
            {
                temp=temp.substr(1,temp.length());
                if(temp.length()>0)
                {
                    int num=stoi(temp,nullptr,2);
                    if(num>=1 and num<=n)
                    {
                        st.insert(num);
                    }
                }
                start++;
            }
        }
        if(st.size()==n)
        {
            return true;
        }
        return false;
    }
};