class Solution {
public:
    int f(string word)
    {
        unordered_map<char,int> m;
        sort(begin(word),end(word));
        for(auto it: word)
        {
            m[it]++;
        }
        return m[word[0]];
    }
    vector<int> numSmallerByFrequency(vector<string>& nums1, vector<string>& nums2) {
       vector<int> ans(nums1.size(),0);
        vector<int> res(nums2.size());
        for(int i=0;i<nums2.size();i++)
        {
            res[i] = f(nums2[i]);
        }
        sort(res.begin(),res.end());
        for(int i=0;i<nums1.size();i++)
        {
            int x = f(nums1[i]);
            int y = upper_bound(res.begin(),res.end(),x) - res.begin();
            ans[i] = res.size()-y;
            
        }
        return ans;
    }
};