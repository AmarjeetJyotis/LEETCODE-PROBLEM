class Solution {
public:
 
    int smallestRepunitDivByK(int k) {
        int m=k;
        if(k%2==0 || k%5==0)return -1;
        int digits=0,c=0;
         m=k;
        while(m!=0)m=m/10,digits=digits*10+1,c++;
        
        int rem=(digits%k);
        while(rem!=0){
            c++;
            rem=rem*10+1;
            rem=rem%k;
        }
        return c;
    }
};