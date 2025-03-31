class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int i = 0, cur = tops[0], count1 = 0, start1 = 1, counter1 = 0;
        while(i < n && start1 < n){
            if(tops[i] != cur){
                counter1 = 0;
                if(bottoms[i] == cur){
                    count1++;
                    i++;
                    counter1++;
                }
                else{
                    i = 0;
                    cur = tops[start1++];
                    count1 = 0;
                }
            }
            else{
                i++;
                counter1++;
            }
        }
        bool topPossible = false;
        if(counter1 > 0){
            topPossible = true;
        }


        i = 0; cur = bottoms[0];
        int count2 = 0, start2 = 1, counter2 = 0;
        while(i < n && start2 < n){
            if(bottoms[i] != cur){
                counter2 = 0;
                if(tops[i] == cur){
                    count2++;
                    i++;
                    counter2++;
                }
                else{
                    i = 0;
                    cur = bottoms[start2++];
                    count2 = 0;
                }
            }
            else{
                i++;
                counter2++;
            }
        }
        bool bottomPossible = false;
        if(counter2 > 0){
            bottomPossible = true;
        }


        int ans;
        if(topPossible && bottomPossible){
            ans = min(count1, count2);
            return ans;
        }
        if(topPossible){
            return count1;
        }
        if(bottomPossible){
            return count2;
        }



        return -1;
    }
};