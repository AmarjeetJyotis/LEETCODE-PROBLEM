class Solution {
public:
    int M=1e9+7;
    int binexp(int a,int b){
        int ans=1;
        while(b){
            if(b&1){
                ans=(ans*1LL*a)%M;
            }
            a=(a*1LL*a)%M;
            b>>=1;
        }
        return ans;
    }
    int maxNiceDivisors(int primeFactors) {
        if(primeFactors<5)return primeFactors;
        int l=primeFactors/3;
        int remain=primeFactors-3*l;
        if(remain==0)  return binexp(3,l);
        if(remain==2)  return (binexp(3,l)*1LL*2)%M;
        return (binexp(3,l-1)*1LL*4)%M;
        
            
        

    }
};