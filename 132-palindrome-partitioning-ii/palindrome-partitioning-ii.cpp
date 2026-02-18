class Solution {
public:
int help(int i, string &s, vector<vector<bool>>& pal,
         vector<int>& dp) {

    if(i == s.size())
        return -1;   // no cut needed beyond end

    if(dp[i] != -1)
        return dp[i];

    int ans = INT_MAX;

    for(int j = i; j < s.size(); j++) {

        if(pal[i][j]) {

            ans = min(ans, 1 + help(j+1, s, pal, dp));
        }
    }

    return dp[i] = ans;
}
    int minCut(string s) {
        int n=s.length();
        vector<vector<bool>>pal(n,vector<bool>(n,false));
        // Precompute palindrome
        for(int i = n-1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if(s[i] == s[j] &&
                (j - i <= 2 || pal[i+1][j-1]))
                    pal[i][j] = true;
            }
        }
        vector<int>dp(n,-1);
        return help(0,s,pal,dp);
    }
};