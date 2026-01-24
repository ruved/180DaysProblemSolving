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
       int n=coins.size();
        vector<unsigned int>dp(amount+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=coins[i];j<=amount;j++){
                dp[j]+=dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};