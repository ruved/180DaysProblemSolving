class Solution {
public:
   int solve(vector<int>& arr, int picks) {
        int m = arr.size();
        
        // dp[i][k] = max sum using first i elements picking exactly k slices
        vector<vector<int>> dp(m + 1, vector<int>(picks + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int k = 1; k <= picks; k++) {
                
                // Skip current slice
                dp[i][k] = dp[i - 1][k];
                
                // Take current slice
                int take = arr[i - 1];
                if (i >= 2)
                    take += dp[i - 2][k - 1];
                else if (k > 1)
                    take = 0;  // invalid case
                
                dp[i][k] = max(dp[i][k], take);
            }
        }
        
        return dp[m][picks];
    }

    int maxSizeSlices(vector<int>& slices) {
        int total = slices.size();
        int n = total / 3;
        
        // Case 1: exclude first slice
        vector<int> case1(slices.begin() + 1, slices.end());
        
        // Case 2: exclude last slice
        vector<int> case2(slices.begin(), slices.end() - 1);
        
        return max(solve(case1, n), solve(case2, n));
    }
};