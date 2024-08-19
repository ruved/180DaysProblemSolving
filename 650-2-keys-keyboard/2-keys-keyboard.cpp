class Solution {
public:
int help(int &total,int n,int last,vector<vector<int>>&dp){
    if(n==total) return 0;
    if(n>total) return INT_MAX;

    if(dp[n][last]!=-1) return dp[n][last];
    int op1=INT_MAX;
    if(n!=last)
    op1=help(total,n,n,dp);
    
    int op2=help(total,n+last,last,dp);
    int val=min(op1,op2);
    return dp[n][last]=(val!=INT_MAX?val+1:val);
}
    int minSteps(int n) {
        if(n==1) return 0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int a=n;
        return 1+help(n,1,1,dp);
    }
};