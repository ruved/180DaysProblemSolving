class Solution {
public:
     int n;
    vector<vector<int>> dp;

    int getLen(int cnt) {
        if (cnt == 1) return 1;
        if (cnt < 10) return 2;
        if (cnt < 100) return 3;
        return 4;
    }

    int solve(string &s, int i, int k) {
    if (k < 0) return 1e9;
    if (i >= n) return 0;

    if (dp[i][k] != -1) return dp[i][k];

    int res = 1e9;

    // OPTION 1: delete this character
    if (k > 0)
        res = solve(s, i + 1, k - 1);

    int same = 0, del = 0;

    for (int j = i; j < n; j++) {
        if (s[j] == s[i]) same++;
        else del++;

        if (del > k) break;

        res = min(res,
            getLen(same) + solve(s, j + 1, k - del));
    }

    return dp[i][k] = res;
}

    int getLengthOfOptimalCompression(string s, int k) {
        n = s.length();
        dp.assign(n, vector<int>(k + 1, -1));
        return solve(s, 0, k);
    }
};