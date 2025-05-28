class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : nums1(nums1), nums2(nums2) {
        for (int x : nums1) freq1[x]++;
        for (int x : nums2) freq2[x]++;
    }

    void add(int index, int val) {
        if (index >= 0 && index < nums2.size()) {
            int prev = nums2[index];
            freq2[prev]--;
            nums2[index] += val;
            freq2[nums2[index]]++;
        }
    }

    int count(int tot) {
        int counter = 0;
        for (const auto& [b, freq_b] : freq2) {
            int a = tot - b;
            if (freq1.count(a)) {
                counter += freq_b * freq1[a];
            }
        }
        return counter;
    }

private:
    vector<int> nums1, nums2;
    unordered_map<int, int> freq1, freq2;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */