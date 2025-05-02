class Solution {
public:
    void IMPL(string &s, int start, int end, char ch) {
        for (int i = start; i < end; i++) {
            s[i] = ch;
        }
    }

    string pushDominoes(string dominoes) {
        vector<pair<char, int>> MARK;

        // Mark all non-dot dominoes with their index
        for (int i = 0; i < dominoes.size(); i++) {
            if (dominoes[i] != '.') {
                MARK.push_back({dominoes[i], i});
            }
        }

        // Edge case: no force applied
        if (MARK.empty()) return dominoes;

        for (int i = 0; i < MARK.size(); i++) {
            if (MARK[i].first == 'L') {
                if (i == 0) {
                    // No force before this, so fill all left of L with L
                    IMPL(dominoes, 0, MARK[i].second, 'L');
                } else if (MARK[i - 1].first == 'R') {
                    // Case: R ... L
                    int left = MARK[i - 1].second;
                    int right = MARK[i].second;
                    int dist = right - left - 1;
                    int mid = dist / 2;

                    // Fill 'R' from left+1 to middle
                    IMPL(dominoes, left + 1, left + 1 + mid, 'R');

                    // If the gap is odd, middle stays '.', otherwise fill up to middle
                    if (dist % 2 == 1) {
                        // Leave the exact middle as '.'
                        // nothing to do, it's already '.'
                    }

                    // Fill 'L' from right-mid to right-1
                    IMPL(dominoes, right - mid, right, 'L');
                } else {
                    // Fill all between previous L and this L
                    IMPL(dominoes, MARK[i - 1].second + 1, MARK[i].second, 'L');
                }
            } else if (MARK[i].first == 'R') {
                if (i == MARK.size() - 1) {
                    // Last force is R, so all to the right fall R
                    IMPL(dominoes, MARK[i].second + 1, dominoes.size(), 'R');
                } else if (MARK[i + 1].first != 'L') {
                    // Next force is also R, so all between become R
                    IMPL(dominoes, MARK[i].second + 1, MARK[i + 1].second, 'R');
                }
                // If next is 'L', it's handled in the L case above
            }
        }

        return dominoes;
    }
};