class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> map1;

        for(auto it : arr)
        {
            map1[it]++;
        }


        int count =-1; 

        for(auto x : map1)
        {
            if(x.first == x.second)
            {
                count = max(count,x.first);

            }
        }

        return count;

        
    }
};