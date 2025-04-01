class MajorityChecker {
public:
    vector<vector<int>> v;
    vector<int> a;
    MajorityChecker(vector<int>& arr) {
        a = arr;
        v.resize(*max_element(a.begin(), a.end()) + 1);
        for (int i = 0; i < a.size(); ++i)
            v[a[i]].push_back(i);
    }
    
    int query(int l, int r, int t) {
        for (int i = 0; i < 100; ++i){
            int n = a[l + random() % (r - l + 1)];
            if (valid(l, r, t, n))
                return n;
        }
        return -1;
    }

    bool valid(int l, int r, int t, int n){
        auto u = upper_bound(v[n].begin(), v[n].end(), r);
        if (u == v[n].begin()) return 0;
        u = prev(u);
        return (u - lower_bound(v[n].begin(), v[n].end(), l) + 1) >= t;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */