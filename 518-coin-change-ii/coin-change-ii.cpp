class Solution {
public:
int help(int amount, vector<int>& coins,int i,vector<vector<int>>&dp){
    if(amount==0) return 1;
    if(i<0||amount<0) return 0;
    if(dp[amount][i]!=-1) return dp[amount][i];
    return  dp[amount][i]=help(amount-coins[i],coins,i,dp)+help(amount,coins,i-1,dp);
}
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(amount+1,vector<int>(coins.size()+1,-1));
        return help(amount,coins,coins.size()-1,dp);
    }
};