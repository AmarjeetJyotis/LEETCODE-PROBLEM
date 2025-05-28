class Solution {
public:
    bool checkZeroOnes(string s) {
        int a=0,b=0,x=0,y=0;
        for(char c:s){
            if(c=='0'){
                x++;
                b=max(b,y);
                y=0;
            }
            else{
                y++;
                a=max(a,x);
                x=0;
            }}
            a=max(a,x);
            b=max(b,y);
        return (a<b);
    }
};