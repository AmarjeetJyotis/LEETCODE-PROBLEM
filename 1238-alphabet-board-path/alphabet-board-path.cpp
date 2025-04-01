class Solution {
public:
    string alphabetBoardPath(string target) {
        int cur = 0;
        string ans = "";
        for(int i=0; i<target.size(); ++i) {
            int index = target[i] - 'a';
            if (index == cur) {
                ans += '!';
                continue;
            } 

           
            int r = cur/5;
            int c = cur%5;
			int r_new = index/5;
            int c_new = index %5;
            
            if (r == 5) {                
                ans.append(abs(r_new-r), r_new < r ? 'U' : 'D');
                ans.append(abs(c_new-c), c_new < c ? 'L' : 'R');
            } else {
                ans.append(abs(c_new-c), c_new < c ? 'L' : 'R');
                ans.append(abs(r_new-r), r_new < r ? 'U' : 'D');
            }            
            ans += '!';
            cur = index;
        }
        return ans;
    }
};