class Solution {
public:
int help(int amount, vector<int>& coins,int i,vector<vector<int>>&dp){
    if(amount==0) return 1;
    if(i<0) return 0;

    if(dp[amount][i]!=-1) return dp[amount][i];
    int take=0;
    if(coins[i]<=amount)
        take=help(amount-coins[i],coins,i,dp);
    int notake=help(amount,coins,i-1,dp);
    return dp[amount][i]=take+notake;
}


    int change(int amount, vector<int>& coins) {
        sort(coins.begin(),coins.end());
        int n=coins.size();
        vector<vector<int>>dp(amount+1,vector<int>(n,-1));
        return help(amount,coins,n-1,dp);
    }
};