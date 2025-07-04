class Solution {
public:

    string base;
    int sz;

    char add_one(char ch)
    {
        int v = ch-'a';
        char nch = (v+1)%26 + 'a';
        return nch;
    }

    char rec(int r, long long off, vector<int> &operations)
    {
        if ((1LL<<r)<=sz) return base[off-1];

        long long half = (1LL<<r)/2;
        if (half < off) 
        {
            char v = rec(r-1, off-half, operations);
            if (operations[r-1]) v = add_one(v);
            return v;
        }
        return rec(r-1, off, operations);
    }

    char kthCharacter(long long k, vector<int>& operations) {
        int n = operations.size();

        base = "a";
        for (int i=0; i<min(n,4); i++)
        {
            if (operations[i]==0) base += base;
            else
            {
                string old = base;
                for (auto c:old) base += add_one(c);
            }
        }
        sz = base.size();
        if (sz>k) return base[k-1];

        long long val = 2, pw = 1;
        while (val < k)
        {
            val *= 2;
            pw++;
        }
        char ans = rec(pw, k, operations);
        return ans;
    }
};