class Solution {
public:
    int maxDistance(string s, int k) {
        int maxDistance = 0 ;

        auto findManhattanDist = [&](char N, char S, char E, char W) -> void
        {
            int x=0, y=0, change=k ;
            for(auto dir: s) {
                if(dir==N) x++ ;
                if(dir==E) y++ ;
                if(dir==S) {
                    if(change) change--, x++ ;
                    else x-- ;
                }
                if(dir==W) {
                    if(change) change--, y++ ;
                    else y-- ;
                }

                int dist = abs(x) + abs(y);
                maxDistance = max(maxDistance, dist) ;
            }
        };

        findManhattanDist('N', 'S', 'E', 'W');
        findManhattanDist('N', 'S', 'W', 'E');
        findManhattanDist('S', 'N', 'E', 'W');
        findManhattanDist('S', 'N', 'W', 'E');
        
        return maxDistance ;
    }
};