class Solution {
public:

    void bfs(int src, int n, vector<int> &dist, vector<vector<int>>& redAdj, vector<vector<int>>& blueAdj) {
        
        vector<vector<int>> vis(n, vector<int>(2, 0)); 
        queue<pair<int, int>> q; 

        dist[src] = 0;
        q.push({src, 0}); 
        q.push({src, 1}); 

        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [node, color] = q.front();
                q.pop();

                vector<int>& neighbors = (color == 0) ? redAdj[node] : blueAdj[node];

                for (int ngh : neighbors) {
                    if (!vis[ngh][color]) {
                        vis[ngh][color] = 1;
                        dist[ngh] = min(dist[ngh], level + 1);
                        q.push({ngh, 1 - color}); 
                    }
                }
            }
            level++;
        }
    }

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<vector<int>> redAdj(n), blueAdj(n);
        for (auto &edge : redEdges) redAdj[edge[0]].push_back(edge[1]);
        for (auto &edge : blueEdges) blueAdj[edge[0]].push_back(edge[1]);

        vector<int> dist(n, INT_MAX);
        bfs(0, n, dist, redAdj, blueAdj);

        for (int &d : dist) {
            if (d == INT_MAX) d = -1;
        }

        return dist;
    }
};