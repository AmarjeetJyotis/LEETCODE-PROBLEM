class Solution {
public:
    #define p pair<int,int>
    #define ll long long
    struct Compare {
        bool operator()(auto &a, auto &b) {
            if(a.first!=b.first)
               return a.first>b.first;
            return a.second>b.second;   
        }
    };
    vector<int> getOrder(vector<vector<int>>& tasks) 
    {
        int n=tasks.size();
        for(int i=0;i<n;i++)
            tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end());
        vector<int>res;
        ll j=0,t=0;
        priority_queue<p,vector<p>,Compare>pq;
        while(j<n || !pq.empty())
        {
            if(j<n && tasks[j][0]>t && pq.empty())
               t=tasks[j][0];
            while(j<n && tasks[j][0]<=t)
            {
                pq.push({tasks[j][1],tasks[j][2]});
                j++;
            }
            // Process task
            res.push_back(pq.top().second);
            t+=pq.top().first;
            pq.pop();
        }
        return res;
    }
};