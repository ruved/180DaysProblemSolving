class Solution {
public:
int n;
    vector<vector<int>> dp;

    int solve(int l, int r, string &text) {
        if (l > r) return 0;
        if (l == r) return 1;

        if (dp[l][r] != -1) return dp[l][r];

        int ans = 1; // whole substring as single chunk

        for (int len = 1; l + len - 1 < r - len + 1; len++) {

            bool match = true;
            for (int i = 0; i < len; i++) {
                if (text[l + i] != text[r - len + 1 + i]) {
                    match = false;
                    break;
                }
            }

            if (match) {
                ans = max(ans, 2 + solve(l + len, r - len, text));
            }
        }

        return dp[l][r] = ans;
    }

    int longestDecomposition(string text) {
        n = text.size();
        dp.assign(n, vector<int>(n, -1));
        return solve(0, n - 1, text);
    }

};