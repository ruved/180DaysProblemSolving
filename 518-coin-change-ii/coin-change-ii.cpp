class Solution {
public:
    int help(vector<int>& coins,int i, int amount,vector<vector<int>>&dp)
    {
        if(i<0) return 0;
        if(amount==0)
            return 1;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int take=0;
        int dont=0;
        if(amount>=coins[i]){
            take=help(coins,i,amount-coins[i],dp);
        }
        dont=help(coins,i-1,amount,dp);
        return dp[i][amount]=take+dont;
        
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans=help(coins,coins.size()-1,amount,dp);
        if(ans==INT_MAX)
            return 0;
        return ans;
    }
};