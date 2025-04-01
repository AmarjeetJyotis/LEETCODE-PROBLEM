class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> prefix(n + 1, 0);
        for(auto i : bookings){
            prefix[i[0] - 1] += i[2];
            prefix[i[1]] -= i[2];
        }

        int sum = 0;
        for(int i = 0;i < n;i++){
            sum += prefix[i];
            prefix[i] = sum;
        }
        prefix.pop_back();

        return prefix;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();