class Solution {
public:
vector<int> dp;

    bool help(int n) {
        if(n == 0) return false;

        if(dp[n] != -1) return dp[n];

        for(int j = 1; j*j <= n; j++) {
            if(!help(n - j*j))
                return dp[n] = true;
        }

        return dp[n] = false;
    }

    bool winnerSquareGame(int n) {
        dp.assign(n+1, -1);
        return help(n);
    }
};