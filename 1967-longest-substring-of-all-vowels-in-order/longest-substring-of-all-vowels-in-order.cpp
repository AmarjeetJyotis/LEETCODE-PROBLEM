class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int count=1,ans=0,left=0;
        for(int right=1;right<word.size();++right){
            if(word[right]<word[right-1]){
                count=1;
                left=right;
            }
            else if(word[right]>word[right-1]){
                count++;
            }
            if(count==5){
                ans=max(ans,right-left+1);
            }

        }
        return ans;
    }
};