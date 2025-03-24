class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i=0;
        int n=intervals.size();
        
        while (i < n && intervals[i][1] < newInterval[0]) i++;

        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            intervals.erase(intervals.begin() + i);
            n--; //size is decreased as one element is deleted.
        }

        intervals.insert(intervals.begin() + i, newInterval);
        
        return intervals;
    }
};