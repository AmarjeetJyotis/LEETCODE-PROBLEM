class Solution {
public:
    long long flowerGame(int n, int m) {
        long long output=0;
        for(int i=1;i<=min(n,m);i++)
        {
            if(i%2==0)
            output=output+(max(n,m)+max(n,m)%2)/2;
            else
            output=output+(max(n,m)-max(n,m)%2)/2;
        }
        return output;
    }
};