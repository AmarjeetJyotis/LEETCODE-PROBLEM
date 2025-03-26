class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        vector<int> rest;
        int row=0, col=0;
        int thresh=100;
        int res=0;
        int count=0;
        for(int i=0;i<s.size();i++)
        {
            if(res+ widths[s[i]-97]>100)
            {
                row+=1;
                res=0;
                res+= widths[s[i]-97];
            }
            else
            {
                res+=widths[s[i]-97];
            }
        }
        rest.push_back(row+1);
        rest.push_back(res);
        return rest;
    }
};