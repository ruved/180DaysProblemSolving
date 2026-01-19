class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));
    int ans = 0;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            pref[i][j] = mat[i-1][j-1] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
            
            // Check if a square of side (ans + 1) exists ending at (i, j)
            int L = ans + 1;
            if (i >= L && j >= L) {
                int currentSum = pref[i][j] - pref[i-L][j] - pref[i][j-L] + pref[i-L][j-L];
                if (currentSum <= threshold) {
                    ans = L; // If valid, we try to find a larger one in the next iterations
                }
            }
        }
    }
    return ans;
}
};