class Solution {
public:
    int reinitializePermutation(int n) {
        int h=n/2;
        int i=1;
        int cnt=0;
        while(1){
            if(i<h){
                i=i*2;
            }
            else i=((i*2)+1)%n;
            cnt++;
            if(i==1)return cnt;
        }
        return 0;
    }
};