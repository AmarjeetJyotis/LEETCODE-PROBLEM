class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int swap = 1;
        int noSwap = 0;
        
        for (int i = 1; i < nums1.size(); i++) {
            int curSwap = 0;
            int curNoSwap = 0;

            if (nums1[i] <= nums1[i-1] || nums2[i] <= nums2[i-1]) {
                // musn't have swapped if swapping; else must have swapped
                curSwap = noSwap + 1;
                curNoSwap = swap;
            } else if (nums1[i] <= nums2[i-1] || nums2[i] <= nums1[i-1]) {
                // must have swapped if swapping; else musn't have
                curSwap = swap + 1;
                curNoSwap = noSwap;
            } else {
                curSwap = min(swap, noSwap) + 1;
                curNoSwap = min(swap, noSwap);
            }

            swap = curSwap;
            noSwap = curNoSwap;
        }

        return min(swap, noSwap);
    }
};