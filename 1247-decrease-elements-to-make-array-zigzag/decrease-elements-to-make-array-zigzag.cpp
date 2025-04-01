class Solution {
public:

    int rec(int i,vector<int>v){

        int ans=0;
        for(;i<v.size();i+=2)
        {
            if(i-1>=0&&v[i-1]<=v[i])
            {
                ans+=v[i]-v[i-1]+1;
                v[i]=v[i-1]-1;
            }

            if(i+1<v.size()&&v[i+1]<=v[i])
            {
                ans+=v[i]-v[i+1]+1;
                v[i]=v[i+1]-1;
            }
        }
        return ans;
    }

    int movesToMakeZigzag(vector<int>& v) 
    {
        int ans=rec(0,v);   // decreasing even indices 
        ans=min(ans,rec(1,v));  // decreasing odd indices 
        return ans;
    }
};