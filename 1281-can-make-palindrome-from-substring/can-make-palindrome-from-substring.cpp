class Solution {
    vector<vector<int>> data;
public:
    bool compute(int start, int end, int rep) {
        vector<int> state = data[end];
        int total = 0;
        int odd = 0;

        for(int i=0;i<26;i++) {
            if(start!=-1)
                state[i] -= data[start][i];
            total += state[i];
            if(state[i]&1) odd++;
        }
        cout<<endl;

        if(total&1) {
            odd--;
        } 

        odd/=2;
        return odd<=rep;
        
    }

    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        //store data format

        vector<int> countLetter(26, 0);
        for(int i=0;i<s.size();i++) {
            countLetter[s[i]-'a']++;
            data.push_back(countLetter);
        }

        // compute

        vector<bool> ans;
        for(int i=0;i<queries.size();i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            int rep = queries[i][2];

            ans.push_back(compute(start-1, end, rep));
        }

        return ans;
    }
};