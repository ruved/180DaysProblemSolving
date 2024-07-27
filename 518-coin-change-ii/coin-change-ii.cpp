class Solution {
public:
int help(vector<int>& coins, int amount,int i,vector<vector<int>>&dp){
    if(amount==0) return 1;
    if(i<0) return 0;

    if(dp[i][amount]!=-1) return dp[i][amount];

    int take=0,notake=0;
    if(amount>=coins[i])
        take=help(coins,amount-coins[i],i,dp);
    
    notake=help(coins,amount,i-1,dp);
    return dp[i][amount]=take+notake;
}
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans= help(coins,amount,coins.size()-1,dp);
        return ans;
    }
};