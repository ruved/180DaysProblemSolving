class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        vector<int> result;

        for (int i = 1; i <= n; ++i) {
            if (dp[i] != numWays[i - 1]) {
                // Assume i is a denomination
                result.push_back(i);
                for (int j = i; j <= n; ++j) {
                    dp[j] += dp[j - i];
                }
            }
        }

        // Final verification
        for (int i = 1; i <= n; ++i) {
            if (dp[i] != numWays[i - 1]) return {};
        }

        return result;
    }
};