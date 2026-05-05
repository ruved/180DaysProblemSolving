class Solution {
public:
int help(vector<int>& coins, int amount,int i,vector<vector<int>>&dp){
    if(amount==0) return 0;
    if(i<0||amount<0) return INT_MAX;
    if(dp[amount][i]!=-1) return dp[amount][i];
    int ans=INT_MAX;
    if(amount>=coins[i]){
        int temp=help(coins,amount-coins[i],i,dp);
        if(temp!=INT_MAX) ans=min(ans,temp+1);
    }
    return dp[amount][i]=min(ans,help(coins,amount,i-1,dp));
}
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        int n=coins.size();
        // vector<vector<int>>dp(amount+1,vector<int>(n,-1));
        // int ans= help(coins,amount,n-1,dp);
        // return ans==INT_MAX?-1:ans;
        vector<int>dp(amount+1,1e5);
        dp[0]=0;
        for(int i=0;i<n;++i){
            for(int j=coins[i];j<=amount;++j)
                dp[j]=min(1+dp[j-coins[i]],dp[j]);
        }
        return dp[amount]==1e5?-1:dp[amount];

    }
};