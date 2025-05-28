class Solution {
public:
    vector<int> assignTasks(vector<int>& s, vector<int>& t) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> fs;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> bs;
        
        // Initialize the free servers heap
        for(int i=0; i<s.size(); i++){
            fs.push({s[i], i}); 
        }
        vector<int> ans(t.size());

        for(int i=0; i<t.size(); i++){
            // Move servers from busy to free if their tasks are done
            while(!bs.empty() && bs.top().first <= i){
                auto [x, server] = bs.top();
                fs.push(server);
                bs.pop();
            }
            // If there are free servers, assign the task to the most suitable server
            if(!fs.empty()){
                auto [server, idx] = fs.top();
                fs.pop();
                ans[i] = idx;
                // Add the server to the busy heap with the time it will be free
                bs.push({i+t[i], {server,idx}});
            }

            // If no servers are free, wait for the next available server
            else{
                auto [time, server] = bs.top();
                bs.pop();
                time += t[i];
                ans[i] = server.second;
                // Update the busy heap with the new free time
                bs.push({time, {server}});
            }
        }

        return ans;
    }
};