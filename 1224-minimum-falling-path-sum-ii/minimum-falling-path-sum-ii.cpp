class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& points) {
         int m = points.size(), n = points[0].size();

        // dp[c] = best score ending at column c in previous row
        vector<long long> dp(points[0].begin(), points[0].end());

        for (int r = 1; r < m; r++) {
            vector<long long> new_dp(n, 0);

            // Step 1: build prefixMax for left case
            vector<long long> prefix(n);
            prefix[0] = dp[0] + 0;
            for (int c = 1; c < n; c++) {
                prefix[c] = min(prefix[c - 1], dp[c]);
            }

            // Step 2: build suffixMax for right case
            vector<long long> suffix(n);
            suffix[n - 1] = dp[n - 1] ;
            for (int c = n - 2; c >= 0; c--) {
                suffix[c] = min(suffix[c + 1], dp[c]);
            }

            // Step 3: compute new dp for row r
            for (int c = 0; c < n; c++) {
                long long best = 0;
                if(c==0) best=suffix[c+1];
                else if(c==n-1) best=prefix[c-1];
                else  best = min(prefix[c-1] , suffix[c+1]);
                new_dp[c] = points[r][c] + best;
            }

            dp.swap(new_dp); // move to next row
        }

        return *min_element(dp.begin(), dp.end());
    }
};