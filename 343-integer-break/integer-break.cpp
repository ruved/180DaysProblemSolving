class Solution {
public:
int help(int n,vector<int>&dp){ 
    if(n<1) return 1;
    
    if(dp[n]!=-1) return dp[n];
    int ans=1;
    for(int i=1;i<=n;++i)
       ans=max(ans,i*help(n-i,dp));
    return dp[n]=ans;
}
    int integerBreak(int n) {
        int ans=1;
        vector<int>dp(n+1,-1);
        for(int i=1;i<n;++i){

           ans=max(ans,i*help(n-i,dp));
        }
        return ans;
    }
};