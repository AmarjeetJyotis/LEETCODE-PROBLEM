class Solution {
public:
    bool check(int j1, int j2,vector<vector<int>>& points){
        int n = points.size();
        int x1 = points[j1][0];
        int y1 = points[j1][1];
        int x2 = points[j2][0];
        int y2 = points[j2][1];
        
        for(int i=j2+1; i<j1; i++){
            int x = points[i][0];
            int y = points[i][1];
            
            if(x<=x1 && x >= x2 && y >= y1 && y <= y2) return false;
        }
        return true;
    }
    bool static comp(vector<int>&v1, vector<int>&v2) {
        if(v1[0] == v2[0]) return v1[1] >= v2[1];
        return v1[0] < v2[0];
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        sort(points.begin(),points.end(),comp);
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(i == j) continue;
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
        
                if(y2 >= y1 && check(i,j,points)) ans++;
    
            }
        }
        return ans;
    }
};