class Solution {
public:
int help(vector<int>& prices, int &fee,int i,bool canbuy,vector<vector<int>>&dp){
    if(i>=prices.size()) return 0;
    if(dp[i][canbuy]!=-1) return dp[i][canbuy];
    int add=canbuy?-prices[i]:prices[i]-fee;
    int take=add+help(prices,fee,i+1,!canbuy,dp);
    int skip=help(prices,fee,i+1,canbuy,dp);
    return dp[i][canbuy]=max(take,skip);
}
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return help(prices,fee,0,true,dp);
    }
};