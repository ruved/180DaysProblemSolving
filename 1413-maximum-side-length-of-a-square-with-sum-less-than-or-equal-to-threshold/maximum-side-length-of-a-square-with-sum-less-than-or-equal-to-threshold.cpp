class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));

        // 1. Build 2D Prefix Sum
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                pref[i][j] = mat[i-1][j-1] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
            }
        }

        // 2. Binary Search for the maximum side length
        int low = 1, high = min(m, n), ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (hasSquare(pref, mid, threshold)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

private:
    bool hasSquare(vector<vector<int>>& pref, int L, int threshold) {
        for (int i = L; i < pref.size(); ++i) {
            for (int j = L; j < pref[0].size(); ++j) {
                // Use the 2D Prefix Sum formula
                int currentSum = pref[i][j] - pref[i-L][j] - pref[i][j-L] + pref[i-L][j-L];
                if (currentSum <= threshold) return true;
            }
        }
        return false;
    }
};