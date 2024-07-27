class Solution {
public:
int help(vector<int>& coins, int amount,int i,vector<vector<int>>&dp){
    if(amount==0) return 0;
    if(i<0) return INT_MAX;

    if(dp[i][amount]!=-1) return dp[i][amount];

    int take=INT_MAX,notake=INT_MAX;
    if(amount>=coins[i])
    {
        take=help(coins,amount-coins[i],i,dp);
        if(take!=INT_MAX)
            take++;
    }
    notake=help(coins,amount,i-1,dp);
    return dp[i][amount]=min(take,notake);
}
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans= help(coins,amount,coins.size()-1,dp);
        return ans==INT_MAX?-1:ans;
    }
};