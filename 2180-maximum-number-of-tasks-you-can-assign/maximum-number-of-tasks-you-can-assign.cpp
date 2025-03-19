class Solution {
public:
    bool helper(vector<int>& tasks, vector<int>& workers, int pills, int strength, int k){
        if(k == 0) return true;
        multiset<int> wks(workers.end() - k, workers.end());
        for(int i = k-1; i >= 0; i--)
        {
            int t = tasks[i];
            if(tasks[i] > *wks.rbegin() and pills > 0)
            {
                t -= strength;
                pills--;
            }
            auto x = wks.lower_bound(t);
            if(x == wks.end()) return false;
            wks.erase(x);
        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(workers.begin(), workers.end());
        sort(tasks.begin(), tasks.end());
        int l = 0, r = min(workers.size(), tasks.size());
        while(l < r)
        {
            int m = (l + r + 1)/2;
            if(helper(tasks, workers, pills, strength, m))
            {
                l = m;
            }
            else r = m-1;
        }
        return l;
    }
    // 2 - 3
    // 3
};