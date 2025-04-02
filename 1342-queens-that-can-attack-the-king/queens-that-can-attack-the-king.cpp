class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>>ans;
        vector<vector<int>>seen(8,vector<int>(8,0));
        for(auto queen:queens){
            seen[queen[0]][queen[1]]=1;
        }
        for(int dx=-1;dx<=1;dx++){
            for(int dy=-1;dy<=1;dy++){
                if(dx==0 && dy==0){
                    continue;
                }
                int x=king[0];
                int y=king[1];
                
                while(x+dx>=0 && y+dy>=0 && x+dx<8 && y+dy<8){
                    x+=dx;
                    y+=dy;
                    if(seen[x][y]){
                        ans.push_back({x,y});
                        break; // ones we got a queen in our current path we will stop
                    }
                }
            }
        }
        return ans;
    }
};