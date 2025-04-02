class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> ans;

        vector<int> mask((1 << n), 0);

        ans.push_back(start);
        mask[start] = 1;

        while (ans.size() < (1 << n)) {
            int last = ans.back();

            for (int i = 0; i < n; i++) {
                int newNum = last ^ (1 << i);
                if (mask[newNum]) continue;
                ans.push_back(newNum);
                mask[newNum] = 1;
                break;
            }
        }
        return ans;
    }
};

/*
    find (2^n - 1)

        010
    110 000 001

    bfs
    visited arr (n * 2^n)

    any combination will take me to the answer as long as I keep flipping by one
*/