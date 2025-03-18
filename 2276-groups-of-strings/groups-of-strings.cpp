class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        const int N = words.size();
        // sort(words.begin(), words.end(),
        //      [](const auto& a, const auto& b) { return a.length() < b.length(); });

        struct DisjSet {
            vector<int> repr, rank;

            DisjSet(int N) : repr(N), rank(N) { iota(repr.begin(), repr.end(), 0); }

// /* 170ms
            // Find with path compression: each node points directly to root after traversal
            int get_repr(int a) { return repr[a] == a ? a : repr[a] = get_repr(repr[a]); };
/**/

/* 190ms
            int get_repr(int a) {
                int r = a;
                for (; r != repr[r]; r = repr[r]);
                for (int i = a, j = repr[i]; i != j; i = j, j = repr[i])
                    repr[i] = r;
                return r;
            };
/**/

            void merge(int a, int b) {
                a = get_repr(a);
                b = get_repr(b);
                rank[a] += rank[a] == rank[b];
                if (rank[a] > rank[b]) // Union by rank: attach shorter tree under taller
                    repr[b] = a;
                else
                    repr[a] = b;
            };
        };

        DisjSet disj_set(N);

        /** Key insight:
         *  The 3 operations (add/delete/replace) are equivalent to removing up to 1 char
         *  from current string and matching against similar removals from previous strings */

        for (int i = 0; i < N; ++i) {
            int mask = str2mask(words[i]);
            // Check if identical letter set was seen before
            // (as original or after 1 char removal from earlier seen)
            if (mask_add1_2_last_idx[mask] >= mask_add1_2_last_idx_offset)
                disj_set.merge(i, mask_add1_2_last_idx[mask] - mask_add1_2_last_idx_offset);
            mask_add1_2_last_idx[mask] = i + mask_add1_2_last_idx_offset;
            // Try removing each present letter to find connected strings
            for (int bp = 0; bp < kAlphaSize; ++bp) {
                int b = 1 << bp;
                if (mask & b) {
                    int m = mask ^ b;
                    if (mask_add1_2_last_idx[m] >= mask_add1_2_last_idx_offset)
                        disj_set.merge(i, mask_add1_2_last_idx[m] - mask_add1_2_last_idx_offset);
                    mask_add1_2_last_idx[m] = i + mask_add1_2_last_idx_offset;
                }
            }
        }

        // Prepare for next test case: invalidate records of mask_add1_2_last_idx via offset incr.
        mask_add1_2_last_idx_offset += N + 1;

        vector<int> repr2count(N);
        for (int i = 0; i < N; ++i)
            ++repr2count[disj_set.get_repr(i)];

        int groups_count = 0;
        int groups_max = 0;
        for (int c : repr2count) {
            groups_count += c > 0;
            groups_max = max(groups_max, c);
        }

        return { groups_count, groups_max };
    }

private:
    static constexpr char kAlphaBeg = 'a';
    static constexpr int kAlphaSize = 'z' - kAlphaBeg + 1;

    // Maps letter set to index of last string connected to it
    static array<int, 1 << kAlphaSize> mask_add1_2_last_idx;
    // Offset distinguishes current values from previous test cases
    // Values below offset are considered unset
    static int mask_add1_2_last_idx_offset;

    static inline int str2mask(const string& s) {
        int m = 0;
        for (char c : s)
            m |= 1 << (c - kAlphaBeg);
        return m;
    }
};

array<int, 1 << Solution::kAlphaSize> Solution::mask_add1_2_last_idx{};
int Solution::mask_add1_2_last_idx_offset = 1;