class Solution {
public:
int help(vector<int>& coins, int amount,int i){
    if(amount==0) return 0;
    if(amount<0||i<0) return INT_MAX;
    int take=INT_MAX,notake=INT_MAX;
    if(amount>=coins[i])
        take=help(coins,amount-coins[i],i);
    notake=help(coins,amount,i-1);
    take=take==INT_MAX?take:take+1;
    return min(take,notake);
 
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        // int ans=help(coins,amount,n-1);
       
        vector<int>dp(amount+1,amount+1);
        dp[0] = 0;
        // return ans==INT_MAX?-1:ans;
        for(int i=0;i<n;++i){
            for(int j=coins[i];j<=amount;++j){
                if(dp[j-coins[i]]!=(amount+1))
                    dp[j]=min(dp[j],1+dp[j-coins[i]]);
            }
        }
        return (dp[amount] > amount) ? -1 : dp[amount];
    }
};