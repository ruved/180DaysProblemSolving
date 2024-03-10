class Solution {
public:
    int help(vector<int>& coins,int i, int amount,vector<vector<int>>&dp)
    {
        if(i<0) return INT_MAX;
        if(amount==0)
            return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int take=INT_MAX;
        int dont=INT_MAX;
        if(amount>=coins[i]){
            take=help(coins,i,amount-coins[i],dp);
            take=take==INT_MAX?take:take+1;
        }
        dont=help(coins,i-1,amount,dp);
        return dp[i][amount]=min(dont,take);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans=help(coins,coins.size()-1,amount,dp);
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};