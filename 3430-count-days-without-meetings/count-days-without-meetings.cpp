class Solution {
public:
// In the question we are given a array having start and end we need to find the no.of days with are not present in any range

// This fuctions simply merge all the overlapping intervals 
    vector<vector<int>> mergeIntervals(vector<vector<int>>&num) {
        vector<vector<int>>ans;
        sort(num.begin(),num.end());
        int mini=num[0][0],maxi=num[0][1],k=0;
        vector<int>take;
        for(int i=0;i<num.size();i++){
            if(maxi>=num[i][0]){
                if(maxi<=num[i][1]){
                maxi=num[i][1];
                }
            }
            else{
                take.push_back(mini);
                take.push_back(maxi);
                ans.push_back(take);
                take.clear();
                mini=num[i][0];
                maxi=num[i][1];
            }
            if(i==(num.size()-1)){
                take.push_back(mini);
                take.push_back(maxi);
                ans.push_back(take);
                take.clear();
                mini=num[i][0];
                maxi=num[i][1];
            }
        }
        return ans;
    }
    int countDays(int days, vector<vector<int>>& meetings) {
        // My logic is we can merge all the overlapping intervals
        meetings=mergeIntervals(meetings);
        // now if we merged all the intervals after that we only have left with unique range value which means we can simply subtract those range from the total no.of days and the left answer will be days on whcih no meetings are scheduled 

        // Also we need to only find the no.of days not the exact days the reason it gets easier to use this logic
        for(int i=0;i<meetings.size();i++)
        days=days-(meetings[i][1]-meetings[i][0]+1);
        return days;
    }
};