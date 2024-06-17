class Solution {
public:


int help(int amount, vector<int>& coins,int i,vector<vector<int>>&dp){
    if(i<0&&amount!=0) return 0;
    if(i<0&&amount==0) return 1;
    if(dp[i][amount]!=-1) return dp[i][amount];
    int take=0,notake=0;
    if(amount>=coins[i]) 
        take=help(amount-coins[i],coins,i,dp);
    notake=help(amount,coins,i-1,dp);
    return dp[i][amount]=take+notake;

}
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,0));
        dp[0]={0};
        dp[0][0]=1;
        int take=0,notake=0;
        for(int i=0;i<coins.size();++i){
            for(int j=0;j<=amount;++j){
                take=0;
                if(j>=coins[i]) 
                 take=dp[i+1][j-coins[i]];//help(amount-coins[i],coins,i,dp);
                    notake=dp[i][j];//help(amount,coins,i-1,dp);
                 dp[i+1][j]=take+notake;
            }
        }
        return dp[coins.size()][amount];
    // return  help(amount,coins,coins.size()-1,dp);

    }
};