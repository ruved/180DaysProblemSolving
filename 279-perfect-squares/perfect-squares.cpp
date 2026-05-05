class Solution {
public:
int help(int n, vector<int>&dp){
    if(n<=0) return n;
    if(dp[n]!=-1) return dp[n];
    int ans=INT_MAX;
    for(int j=1;j*j<=n;++j){
        ans=min(ans,1+help(n-j*j,dp));
    }
    return dp[n]=ans;
}
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return help(n,dp);
    }
};