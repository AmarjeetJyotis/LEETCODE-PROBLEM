class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
      priority_queue<int> maxh;
      int cnt=0;
      for(int i=0; i<flips.size(); i++){
          maxh.push(flips[i]);

          if(maxh.size()==maxh.top()){
              cnt++;
          }
      }
      return cnt;
    }
};