class Solution {
public:
int help(int sum,vector<int>&dp){
    if(sum<=1) return 1;
    if(dp[sum]!=-1) return dp[sum];
    int ans=0;
    for(int i=1;i<=sum;++i){
        int temp=i*help(sum-i,dp);
        ans=max(ans,temp);
    }
    return dp[sum]=ans;
}
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        vector<int>dp(n+1,-1);
        return help(n,dp);
    }
};

// sum=x1+...+xn
// product=x1*...*xn

// 1+1+2+2+2+2= 2*2*2*2
// 1+2+3+4= mul 24

