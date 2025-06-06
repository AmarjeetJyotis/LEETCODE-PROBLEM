class Solution {
public:
    int numberOfRounds(string s, string f) {
        stringstream geek(s.substr(0,2));
        int x = 0;
        geek>>x;
        stringstream geek1(f.substr(0,2));
        int y = 0;
        geek1>>y;
        stringstream geek2(s.substr(3,2));
        int x1 = 0;
        geek2>>x1;
        stringstream geek3(f.substr(3,2));
        int y1 = 0;
        geek3>>y1;
        int m=0;
        int t=0;
        if(x>y){
            m=(24-x-1+y)*4;
        }
        else if(x==y && y1>x1){
            m=0;
            t=1;
        }
        else if(x==y && x1>y1){
            m=23*4;
        }
        else{
            m=(y-x-1)*4;
        }
        if(t==1){
            if(x1>y1 && x!=y){
                int b=ceil((x1-y1)/15.0);
                // cout<<b;
                m+=96-b;
                return m;
            }
            // cout<<x1<<y1;
            y1-=y1%15;
            if(x1%15!=0)
            x1+=(15-x1%15);
            if(y1>x1)
            m+=(y1-x1)/15;
            return m;
        }
        m+=y1/15;
        x1=60-x1;
        m+=x1/15;
        return m;
    }
};