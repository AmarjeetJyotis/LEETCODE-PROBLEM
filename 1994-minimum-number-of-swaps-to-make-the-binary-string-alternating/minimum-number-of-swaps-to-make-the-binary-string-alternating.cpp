class Solution {
private:
    int count(string& s, char c) {
        int miss = 0;
        for (int i = 0; i < s.length(); i += 2) {
            if (s[i] != c) miss++;
        }
        return miss;
    }
public:
    int minSwaps(string s) {
        int cnt0 = 0, cnt1 = 0;
        for (char c : s) c == '0'? cnt0 += 1 : cnt1 += 1;
        if (abs(cnt0 - cnt1) > 1) return -1;
        
        if (cnt0 > cnt1) return count(s, '0');
        if (cnt0 < cnt1) return count(s, '1');
        return min(count(s, '0'), count(s, '1'));
    }
};
