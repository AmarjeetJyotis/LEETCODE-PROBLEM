class Solution {
    private:
    bool solve(vector<int> &arr,int index,vector<bool> &visit){
        if(index < 0 || index >= arr.size() || visit[index]) return false;
        if(arr[index] == 0) return true;
        visit[index] = true;
        bool ans = solve(arr,index+arr[index],visit) || solve(arr,index-arr[index],visit);
        visit[index] = false;
        return ans;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visit(arr.size(),false);
        return solve(arr,start,visit);
    }
};