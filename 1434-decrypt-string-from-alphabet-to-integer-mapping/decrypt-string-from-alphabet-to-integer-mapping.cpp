class Solution {
public:
    string freqAlphabets(string s) {
        string formatted_str;
        for (int i=0; i<s.size(); ++i) {
            const char ch = s[i];
            const bool is_two_digit_num = (ch == '1' || ch == '2') && (i < s.size() - 2 && s[i+2] == '#');
            const int pos = is_two_digit_num ? (ch - '1') * 10 + (s[i+1] - '0') : ch - '1';
            const char mapped_ch = (is_two_digit_num ? 'j' : 'a') + pos;
            formatted_str += string(1, mapped_ch);
            i += is_two_digit_num ? 2 : 0;
        }
        
        return formatted_str;
    }
};