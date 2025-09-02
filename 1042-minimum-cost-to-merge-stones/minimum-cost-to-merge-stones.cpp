class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
         int n = stones.size();

        // ---- Feasibility check ----
        if ((n - 1) % (k - 1) != 0) return -1;

        // ---- Prefix sums ----
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stones[i];
        }
        auto rangeSum = [&](int l, int r) {
            return prefix[r + 1] - prefix[l];
        };

        const int INF = 1e9;

        // dp[l][r][p] = min cost to merge subarray [l..r] into exactly p piles
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(k + 1, INF))
        );

        // Base case: single pile
        for (int i = 0; i < n; i++) {
            dp[i][i][1] = 0;  // cost 0 to make one pile
        }

        // Iterate over interval lengths
        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;

                // Compute dp[l][r][p] for all p = 2..k
                for (int p = 2; p <= k; p++) {
                    // Try splits
                    for (int m = l; m < r; m += (k - 1)) {
                        if (dp[l][m][1] == INF || dp[m + 1][r][p - 1] == INF) continue;
                        dp[l][r][p] = min(dp[l][r][p], dp[l][m][1] + dp[m + 1][r][p - 1]);
                    }
                }

                // Special case: merge into 1 pile
                if (dp[l][r][k] != INF) {
                    dp[l][r][1] = dp[l][r][k] + rangeSum(l, r);
                }
            }
        }

        return dp[0][n - 1][1];
    }
};