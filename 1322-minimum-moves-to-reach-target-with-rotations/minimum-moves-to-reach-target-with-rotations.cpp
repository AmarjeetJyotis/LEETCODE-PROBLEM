class Solution {
   bool isValid(int tr, int tc, int hr, int hc, vector<vector<int>>& grid)
   {
      int n = grid.size();
      return tr < n && tc < n && hr < n && hc < n && grid[tr][tc] == 0 && grid[hr][hc] == 0;
   }
 public:
    int minimumMoves(vector<vector<int>>& grid) {
        unordered_map<string,bool> vis;
        int n = grid.size(), moves = 0;
        queue<vector<int>> q;

        q.push({0,0,1});
        while(!q.empty())
        {
           int size = q.size();
           while(size--)
           {
               auto curr = q.front(); 
                q.pop();

              int tr = curr[0], tc = curr[1], isHorizontal = curr[2], hr, hc;
              string state = to_string(tr) + '$' + to_string(tc) + '$' + to_string(isHorizontal);
              if(vis[state]) continue; //do not visit already visited states
              vis[state] = true;

              if(tr == n-1 && tc == n-2 && isHorizontal) //termination condition
               return moves;

               int newTr,newTc,newHr,newHc;
                if(isHorizontal == 1)
                {
                //CASE 1: move right
                newTr = tr, newTc = tc, newHr = tr, newHc = tc + 2;
                if(isValid(newTr,newTc,newHr,newHc,grid)) 
                  q.push({tr,tc+1,1}); 

                //CASE 2: move down 
                newTr = tr+1, newTc = tc, newHr = tr+1, newHc = tc+1;
                if(isValid(newTr,newTc,newHr,newHc,grid)) 
                 q.push({tr+1,tc,1});

                //CASE 3: rotate clock-wiae
                newTr = tr, newTc = tc, newHr = tr+1, newHc = tc;
                if(isValid(newTr,newTc,newHr,newHc,grid) && grid[tr+1][tc+1] == 0) 
                   q.push({tr,tc,0}); 
                }
               else
               {//CASE 1: move right
                newTr = tr, newTc = tc+1, newHr = tr+1, newHc = tc+1;
                if(isValid(newTr,newTc,newHr,newHc,grid)) 
                 q.push({tr,tc+1,0}); 

                //CASE 2: move down
                newTr = tr+1, newTc = tc, newHr = tr+2, newHc = tc;
                if(isValid(newTr,newTc,newHr,newHc,grid)) 
                 q.push({tr+1,tc,0}); 

                //CASE 3: move anti clock-wise
                newTr = tr, newTc = tc, newHr = tr, newHc = tc+1;
                if(isValid(newTr,newTc,newHr,newHc,grid) && grid[tr+1][tc+1] == 0)  
                   q.push({tr,tc,1});  
               }    
            }
         moves++;
        }
    return -1;
    }
};