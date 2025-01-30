class Solution {
public:

int help(int n,vector<int>&dp){
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    int sqroot=sqrt(n);
    int sq=sqroot*sqroot;
    int res=INT_MAX;
    for(int i=1;i<=sqroot;++i)
        res=min(res,1+help(n-i*i,dp));
    return dp[n]=res;
}   
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return help(n,dp);
    }
};
