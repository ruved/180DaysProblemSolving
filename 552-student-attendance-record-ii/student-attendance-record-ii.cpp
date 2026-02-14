class Solution {
public:
const int mod = 1e9+7;
    long dp[100001][2][3];

    long help(int n, int a, int l) {
        if(n == 0) return 1;
        if(dp[n][a][l] != -1) return dp[n][a][l];

        long ans = 0;

        // Present
        ans = help(n-1, a, 0) % mod;

        // Absent
        if(a == 0)
            ans = (ans + help(n-1, 1, 0)) % mod;

        // Late
        if(l < 2)
            ans = (ans + help(n-1, a, l+1)) % mod;

        return dp[n][a][l] = ans;
    }

    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));
        return help(n, 0, 0);
    }
};