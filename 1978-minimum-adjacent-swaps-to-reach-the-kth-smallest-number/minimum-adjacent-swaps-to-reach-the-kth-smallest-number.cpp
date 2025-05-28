class Solution {
public:
    int getMinSwaps(string str, int k) {

        int n = str.length();

        vector<int> arr(n);
        vector<int> oarr(n);
        for(int i=0; i<n; i++) {
            arr[i] = oarr[i] = str[i] - '0';
        }
 
        for(int a=0; a<k; a++) {
            // find that element from right which is smaller than it's right
            // e.g, 9 8 4* 6 5 2 1

            int i = n-2;
            while(i>=0 && arr[i] >= arr[i+1]) {
                i--;
            }

            if(i < 0) {
                // the given array has the elements arranged in decreasing order
                reverse(arr.begin(), arr.end());
                return 0;
            }

            // find that element from right which is just greater than arr[i]
            // e.g, 9 8 4 6 5* 2 1

            int j = n-1;
            while(j >= 0 && arr[j] <= arr[i]) {
                j--;
            }

            // swap arr[i] with arr[j]
            // e.g, 9 8 5* 6 4* 2 1
            swap(arr[i], arr[j]);

            // reverse the subarray [i+1, n-1] so that element gets arranged in increasing order
            reverse(arr.begin() + i + 1, arr.end());
        }

        int i = 0;
        int sc = 0;

        while(i < n) {
            if(arr[i] == oarr[i]) {
                i++;
            } else {
                // 5489355142
                // 5489355421
                int j = i+1;
                while(oarr[j] != arr[i]) {
                    j++;
                }

                while(j > i) {
                    swap(oarr[j], oarr[j-1]);
                    sc++;
                    j--;
                }
            }
        }
        
        return sc;
    }
};