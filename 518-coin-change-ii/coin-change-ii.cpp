class Solution {
public:
int help(int amount,int i, vector<int>& coins,vector<vector<int>>&dp){
    if(amount==0) return 1;
    if(i<0) return 0;
    if(dp[i][amount]!=-1) return dp[i][amount];

    int take=0,notake=0;
    if(amount>=coins[i])
        take=help(amount-coins[i],i,coins,dp);
    notake=help(amount,i-1,coins,dp);
    return dp[i][amount]= take+notake;

}
    int change(int amount, vector<int>& coins) {
       int n=coins.size();
       vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
     return   help(amount,n-1,coins,dp);
    }
};