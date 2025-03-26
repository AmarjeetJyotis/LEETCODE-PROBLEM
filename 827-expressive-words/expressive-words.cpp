class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        vector<pair<char, int>> v;

        int c = 0;
        while (c < s.size()) {
            int cnt = 1;
            char ch = s[c];
            c++;
            while (c < s.size() && s[c] == ch) {
                cnt++;
                c++;
            }
            v.push_back({ch, cnt});
        }

        int ans = 0;

        for (string x : words) {
            vector<pair<char, int>> vw;

            c = 0;
            while (c < x.size()) {
                int cnt = 1;
                char ch = x[c];
                c++;
                while (c < x.size() && x[c] == ch) {
                    cnt++;
                    c++;
                }
                vw.push_back({ch, cnt});
            }

            if(vw.size() != v.size()){
                continue;
            }

            bool isvalid = true;
            for(int i=0;i<vw.size();i++){
                if(vw[i].first != v[i].first){
                    isvalid = false;
                    break;
                }

                if(vw[i].second > v[i].second){
                    isvalid = false;
                    break;
                }

                if(vw[i].second == 1 && v[i].second == 2){
                    isvalid = false;
                    break;
                }

            }
            
            ans += isvalid;
        }
        return ans;
    }
};