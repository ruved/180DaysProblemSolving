class Solution {
public:
int help(vector<int>& coins, int amount,int i,vector<vector<int>>&dp){
    if(amount==0) return 0;
    if(i<0) return INT_MAX;
    if(dp[amount][i]!=-1) return dp[amount][i];
    int take=INT_MAX;
    if(amount>=coins[i]){
        int temp=help(coins,amount-coins[i],i,dp);
        if(temp!=INT_MAX) 
            take=temp+1;
    }
    
    int notake=help(coins,amount,i-1,dp);
    return dp[amount][i]=min(take,notake);
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(amount+1,vector<int>(n,-1));
        int ans=help(coins,amount,n-1,dp);
        return (ans==INT_MAX)?-1:ans;
    }
};
