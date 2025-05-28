class Solution {
public:
    int numDifferentIntegers(string word) {
        for (int i = 0; i < word.length(); i++) {
            if (word[i] >= 'a' && word[i] <= 'z') {
                word[i] = ' ';
            }
        }

        // Library
        vector<string> vec;
        stringstream ss(word);
        string words;

        while (ss >> words) {
            vec.push_back(words);
        }

        unordered_set<string> uniq;

        for (int i = 0; i < vec.size(); i++) {
            string str = vec[i];

            if (str[0] == '0') {
                reverse(str.begin(), str.end());
                for (int j = str.length() - 1; j >= 0; j--) {
                    if (str[j] == '0') {
                        str.pop_back();
                    } else {
                        break;
                    }
                }

                reverse(str.begin(), str.end());
                uniq.insert(str);
            } else {
                uniq.insert(str);
            }
        }
        return uniq.size();
    }
};