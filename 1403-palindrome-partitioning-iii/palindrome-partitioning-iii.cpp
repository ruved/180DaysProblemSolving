class Solution {
public:
int help(string &s,int i,int k,vector<vector<int>> &cost,vector<vector<int>>&dp){
    if(i>=s.length()&&k==0) return 0;
    if(i>=s.length()||k==0) return INT_MAX;

    if(dp[i][k]!=-1) return dp[i][k];
    int ans=INT_MAX;
    for(int j=i;j<=s.length()-k;++j){
        int temp=help(s,j+1,k-1,cost,dp);
        if(temp!=INT_MAX)
            ans=min(ans,cost[i][j]+temp);
    }
    return dp[i][k]=ans;
}
    int palindromePartition(string s, int k) {
        int n=s.length();
        vector<vector<int>> cost(n, vector<int>(n, 0));

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (len == 2)
                    cost[i][j] = (s[i] != s[j]);
                else
                    cost[i][j] = cost[i+1][j-1] + (s[i] != s[j]);
            }
        }
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return help(s,0,k,cost,dp);
    }
};