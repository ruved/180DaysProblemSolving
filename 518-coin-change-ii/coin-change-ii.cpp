class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        // vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
        // for(int i=0;i<=n;++i) dp[i][0]=1;
        vector<long  unsigned>dp(amount+1,0);
        dp[0]=1;
        for(int i=0;i<n;++i){
            for(int am=coins[i];am<=amount;++am){
               dp[am]+=dp[am-coins[i]];
            }
        }
        return (int)dp[amount];
    }
};