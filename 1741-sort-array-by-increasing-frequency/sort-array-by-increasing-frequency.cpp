class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int cnt = 1;
        for(int i = 0;i < nums.size() - 1;i++){
            if(nums[i] == nums[i + 1]) cnt++;
            else{
                v.push_back({cnt, nums[i]});
                cnt = 1;
            }
        }
        v.push_back({cnt, nums[nums.size() - 1]});

        sort(v.begin(), v.end(),[](const vector<int> &a, const vector<int> &b){
            if(a[0] == b[0]) return a[1] > b[1];
            else return a[0] < b[0];
        });

        for(auto i : v){
            for(int j = 0;j < i[0];j++) ans.push_back(i[1]);
        }
        
        return ans;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();