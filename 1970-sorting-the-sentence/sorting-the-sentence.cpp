class Solution {
public:
    string sortSentence(string s) {
        vector<string> words(9);
        string word;
        int n = s.length(), j = 0;

        for (int i = 0; i < n; ++i) {
            if(s[i] == ' ') 
                j = i + 1;
            else if (isdigit(s[i])) {
                words[s[i] - '1'] = s.substr(j , i - j);
                j = i + 1;
            }
        }

        string result;
        for (int i = 0; i < 9; ++i) {
            if (!words[i].empty()) {
                if (!result.empty()) 
                    result += ' ';
                result += words[i];
            }
        }

        return result;
    }
};