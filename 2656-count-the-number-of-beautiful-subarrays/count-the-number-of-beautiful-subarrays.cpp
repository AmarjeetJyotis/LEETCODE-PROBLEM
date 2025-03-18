class Solution {
public:

    long long beautifulSubarrays(vector<int>& arr) 
    {
        int n = arr.size();
            
        int res = 0;
        map<int,int>mp;
        mp[res]++;
        
        long long count = 0;
        
        for(int i=0; i<n; i++)
        {
            res ^= arr[i];
            mp[res]++;
            count += mp[res]-1;
        }
        
        return count;
    }
};