class Solution {
public:
int help(vector<int>& prices,int buy,int i,vector<vector<int>>&dp){
    if(i>=prices.size()) return 0;

    if(dp[buy+1][i]!=-1) return dp[buy+1][i];
    int take=0,notake=0;
    if(buy==-1)
        take=help(prices,i,i+1,dp);
    else
        take=(prices[i]-prices[buy])+help(prices,-1,i+2,dp);
    notake=help(prices,buy,i+1,dp);
    return dp[buy+1][i]=max(take,notake);
}
    int maxProfit(vector<int>& prices) {
        int buy=-1;
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(n,-1));
        return help(prices,buy,0,dp);
    }
};