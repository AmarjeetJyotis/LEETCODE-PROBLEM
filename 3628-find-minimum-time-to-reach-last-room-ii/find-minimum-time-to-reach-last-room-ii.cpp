struct Node {
    int time;
    bool state; // 0 for previously 2 steps moved, 1 for prev 1
    int x;
    int y;

    // Overload > operator for min-heap since comparison is done by >
    bool operator>(const Node& other) const {
        return time > other.time;
    }
};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();
        int n = moveTime[0].size();
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        pq.push({0, 0, 0, 0});
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        vector<vector<int>> dist(m, vector<int> (n, -1));
        dist[0][0] = 0;
        while(!pq.empty()){
            auto i =  pq.top();
            pq.pop();
            for(int j=0; j<4; j++){
                int nx = i.x+dx[j];
                int ny = i.y+dy[j];
                if(nx>=0 && ny>=0 && nx<m && ny<n){
                    int newTime = max(i.time+1+i.state, moveTime[nx][ny]+1+i.state); //if prev state was 2 now it'll take 1 steps else it'll take 1+i.state(i.e. = 1) steps
                    if(dist[nx][ny]==-1 || dist[nx][ny] > newTime){ // i initially thought even if you are reaching at same cell with = prevDist, you should still push it to pq coz it may happen that this time you are using 2 steps and previously you used 1 step and then u'll be able to move to adj in 1 step this time so a better future step
                    // but it gave me tle... so changed to dist[nx][ny] > newTime and it workerd...but why don't you need a >= ? If you are wondering whether or not value of step (1 or 2) with same weight may impact the solution. The answer is NO.
                    //  Reason : If you took k steps to start with cell (0,0) and take any path to reach (x,y), then if k=(x+y) is odd it will always be odd, if k is even then it will always be even.
                    // because it's a rectilinear or manhattan distance and if you take another path from the shortest one you'll always have to counter it with same amount of returning steps
                        pq.push({newTime, !i.state, nx, ny});
                        dist[nx][ny] = newTime;
                        if(nx==m-1 && ny==n-1) // since here our time function is increasing uniformly only by 1 or 2(depending on state),unlike traditional dijkstra where we may find a better path in future due to non uniform paths, we may return directly here 
                            return newTime;
                    }
                }
            }
        }
        return -1;
    }
};