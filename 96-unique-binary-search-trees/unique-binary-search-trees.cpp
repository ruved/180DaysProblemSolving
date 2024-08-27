class Solution {
public:
int help(int n,vector<int>&dp){
    if(n==1 || n==0)
        return 1;

    if(dp[n]!=-1) return dp[n];
    int result=0;
    for(int i=0;i<n;i++)
        result+=help(i,dp)*help(n-i-1,dp);
    return dp[n]=result;
}   
    int numTrees(int n) {
       vector<int>dp(n+1,-1);
       return help(n,dp);
    }
};
// i=(1,n)
// root=i
// left =(1,i-1)
// right=(i+1,n)







