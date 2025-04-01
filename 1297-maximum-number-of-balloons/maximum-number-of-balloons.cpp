class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mpp;
        int cntb=0;
        int cnta=0;
        int cntl=0;
        int cnto=0;
        int cntn=0;
        for(int i=0;i<text.size();i++){
            mpp[text[i]]++;
            if(text[i]=='b')cntb++;
            if(text[i]=='a')cnta++;
            if(text[i]=='l')cntl++;
            if(text[i]=='o')cnto++;
            if(text[i]=='n')cntn++;
        }
        cntl/=2;
        cnto/=2;
        cout<<cntb<<endl;
        return min({cntb,cntl,cnta,cnto,cntn});
    }
};