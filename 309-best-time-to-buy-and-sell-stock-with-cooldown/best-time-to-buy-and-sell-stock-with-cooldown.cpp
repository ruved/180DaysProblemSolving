class Solution {
public:

int help(vector<int>& prices,bool buy,int i,vector<vector<int>>&dp){
    if(i>=prices.size()) return 0;

    if(dp[buy][i]!=-1) return dp[buy][i];
    int take=0,notake=0;
    if(buy==true)
        take=-prices[i]+help(prices,false,i+1,dp);
    else
        take=prices[i]+help(prices,true,i+2,dp);
    notake=help(prices,buy,i+1,dp);
    return dp[buy][i]=max(take,notake);
}
    int maxProfit(vector<int>& prices) {
        int buy=-1;
        int n=prices.size();
        vector<vector<int>>dp(2,vector<int>(n,-1));
        return help(prices,buy,0,dp);
    }
};