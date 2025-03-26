class Solution 
{
private:

    void dfs(unordered_map<int , vector<int>>& adjList , int current_node , int& dst_node ,vector<int>& current , vector<vector<int>>& ans)
    {
        current.push_back(current_node);

        if(current_node == dst_node)
        {
            ans.push_back(current);
            return;
        }

        for(auto node : adjList[current_node])
        {
            //current.push_back(node);
            dfs(adjList , node , dst_node , current , ans);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        // declarations
        vector<vector<int>> ans;
        vector<int> current;    
        int src = 0;
        int size = graph.size();
        int dst = size-1;
        unordered_map<int , vector<int>> adjList;

        // build adjList
        for(int i = 0 ; i < size ; i++)
        {
           adjList[i].insert(adjList[i].end() , graph[i].begin() , graph[i].end());
        }

        // call dfs
        dfs(adjList , 0 , dst, current , ans);

        // return the answer;
        return ans;
    }
};