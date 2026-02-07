class Solution {
public:
int help(vector<int>& coins, int amount,int i){
    if(i<0&&amount==0) return 0;
    if(i<0) return INT_MAX;
    int res=INT_MAX;
    if(coins[i]<=amount){
        int temp=help(coins,amount-coins[i],i);
        res=temp==INT_MAX?temp:temp+1;
    }
    res=min(res,help(coins,amount,i-1));
    return res;
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        // vector<vector<int>>dp(n,vector<int>(amount+1,amount + 1));
        // int temp= help(coins,amount,n-1);

        vector<int>dp(amount+1,amount+1);
        dp[0]=0;
        for(int i=0;i<coins.size();++i){
            for(int j=coins[i];j<=amount;++j){
                dp[j]=min(dp[j],1+dp[j-coins[i]]);
            }
        }
        return dp[amount]==amount+1?-1:dp[amount];
    }
};