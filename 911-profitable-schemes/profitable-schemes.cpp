class Solution {
public:
int mod=1e9+7;
int help(int n, int minProfit, vector<int>& group, vector<int>& profit,int i,vector<vector<vector<int>>>&dp){
    if(i<0) return minProfit<=0;
    if(dp[n][minProfit][i]!=-1) return dp[n][minProfit][i];
    unsigned int take=0;
    if(n-group[i]>=0)
        take=help(n-group[i],max(0,minProfit-profit[i]),group,profit,i-1,dp);
    unsigned int notake=help(n,minProfit,group,profit,i-1,dp);
    return dp[n][minProfit][i]=(take%mod+notake%mod)%mod;
}
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m=profit.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(minProfit+1,vector<int>(m,-1)));
        return help(n,minProfit,group,profit,m-1,dp);
    }
};