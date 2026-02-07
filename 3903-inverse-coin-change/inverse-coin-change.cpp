class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
       int n = numWays.size();          // sums = 1..n
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;

        vector<int> coins;

        for (int s = 1; s <= n; s++) {
            long long target = numWays[s - 1];

            // already too many ways → impossible
            if (dp[s] > target) {
                return {};
            }

            // missing ways → must add coin s
            if (dp[s] < target) {
                coins.push_back(s);

                for (int j = s; j <= n; j++) {
                    dp[j] += dp[j - s];

                    if (dp[j] > numWays[j - 1]) {
                        return {};
                    }
                }
            }

            // 🔥 CRITICAL CHECK (the missing one)
            if (dp[s] != target) {
                return {};
            }
        }

        return coins;
    }
};