class Solution {
public:
    int findMaxIndex(vector<vector<int>>& mat, int m, int n, int j) {
        int maxi = INT_MIN;
        int index = -1;
        for (int i = 0; i < m; i++) {
            if (mat[i][j] > maxi) {
                maxi = mat[i][j];
                index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int s = 0;
        int e = n - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            int maxRowIndex = findMaxIndex(mat, m, n, mid);

            int left = mid - 1 >= 0 ? mat[maxRowIndex][mid - 1] : -1;
            int right = mid + 1 < n ? mat[maxRowIndex][mid + 1] : -1;

            if (mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right)
                return {maxRowIndex, mid};
            else if (mat[maxRowIndex][mid] < left)
                e = mid - 1;
            else
                s = mid + 1;
        }

        return {-1, -1};
    }
};