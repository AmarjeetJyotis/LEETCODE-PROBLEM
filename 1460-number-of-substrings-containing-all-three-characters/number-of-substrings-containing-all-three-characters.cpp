/*
By   :: savetrees
Used :: Sliding Window
*/
class Solution {
public:
    int numberOfSubstrings(string s) {
        int low = 0, high = 0, a = 0, b = 0, c = 0, cnt = 0;
        while (high < s.length()) {
            if (s[high] == 'a') a++;
            else if (s[high] == 'b') b++;
            else c++;
            
            while (a >= 1 && b >= 1 && c >= 1) {
                cnt += s.length() - high;
                if (s[low] == 'a') a--;
                else if (s[low] == 'b') b--;
                else c--;
                low++;
            }
            high++;
        }
        return cnt;
    }
};