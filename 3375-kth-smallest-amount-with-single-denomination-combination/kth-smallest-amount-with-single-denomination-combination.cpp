class Solution {
public:
    long long lcm(long long a, long long b){
        return (a*b)/gcd(a,b);
    }
//Recursive function to generate all the possible subsets and calculate their contribution.
    long long f(vector<int>&coins, int index,long long val,int picked,long long mid){
        if(index==coins.size()){
            long long ans=0;
            ans+=(mid/val);
            if(mid%val==0)ans--;
            return picked>=1?(picked&1)*ans+(!(picked&1))*-1*ans:0;
        }
        long long pick=0;
        if(lcm(coins[index],val)<=mid)
        pick = f(coins,index+1,lcm(coins[index],val),picked+1,mid);
        long long notpick = f(coins,index+1,val,picked,mid);
        return pick+notpick;
    }
    
// Find function on Binary Search.

    bool find(vector<int>&coins, int k,long long mid){
        return f(coins,0,1,0,mid)>=k-1;
    }
    
//Standard Binary Search on Answer function to find the minimum
    long long BSA(long long low, long long high,vector<int>&f, int h,long long max){
        if(low==high){if(high==max)return -1; else return high;}
        long long mid = low+(high-low)/2;
        if(find(f,h,mid))return BSA(low,mid,f,h,max);
        else return BSA(mid+1,high,f,h,max);
    }
    
    long long findKthSmallest(vector<int>& coins, int k) {
        vector<int>res;
    //Removing those numbers which are multiples as they create duplicate entries.
        for(int i=0;i<coins.size();i++){
            bool flag=true;
            for(int j=0;j<coins.size();j++){
                if(j!=i){
                    if(coins[i]%coins[j]==0)flag=false;
                }
            }
            if(flag)res.push_back(coins[i]);
        }
        
        long long check= BSA(1,1e18,res,k,1e18);
        //Make sure the number belong in the series.
        while(true){
            for(auto it:res){
                if(check%it==0)return check;
            }
            check++;
        }
    }
};