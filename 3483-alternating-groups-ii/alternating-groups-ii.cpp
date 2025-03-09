class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int window=1;
        int n=colors.size(),cnt=0;
        for(int i=0;i<n+k-2;i++){
            if(colors[i%n]!=colors[(i+1)%n]){
                window++;
                if(window>=k){
                    cnt++;
                }
            }else{
                window=1;
            }
        }
        return cnt;
    }
};