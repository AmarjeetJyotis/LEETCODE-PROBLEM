class CountIntervals {
public:
    set<pair<int, int>> s;
    int cur;
    CountIntervals() {
        s.clear();
        cur = 0;
    }

    void add(int left, int right) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        auto it = s.lower_bound({left, right});
        while (it != s.end() and it->first <= right) {
            left = min(it->first, left);
            right = max(it->second, right);
            cur -= (it->second - it->first + 1);
            auto temp = it;
            it++;
            s.erase(temp);
        }

        if (it != s.begin()) {
            it--;
            if (it->second >= left) {
                left = min(it->first, left);
                right = max(it->second, right);
                cur -= (it->second - it->first + 1);
                auto temp = it;
                it++;
                s.erase(temp);
            }
        }

        cur+=right-left+1;
        s.insert({left,right});
    }

    int count() {
        return cur;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */