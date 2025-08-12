class Solution {
public:
int mod=1e9+7;
int help(int n, int &x,int i,vector<vector<int>>&dp){

    if(n==0) return 1;
    int l=pow(i,x);
    if(l>n) return 0;
    if(dp[n][i]!=-1) return dp[n][i];
    long int ans=0;
    ans=(help(n-l,x,i+1,dp)%mod+help(n,x,i+1,dp)%mod)%mod;
    return dp[n][i]=ans;
}
    int numberOfWays(int n, int x) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return help(n,x,1,dp);
    }
};