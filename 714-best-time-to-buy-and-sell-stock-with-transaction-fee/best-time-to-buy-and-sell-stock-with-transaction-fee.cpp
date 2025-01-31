class Solution {
public:
int help(vector<int>& prices,bool buy,int i,vector<vector<int>>&dp,int &fee){
    if(i>=prices.size()) return 0;

    if(dp[buy][i]!=-1) return dp[buy][i];
    int take=0,notake=0;
    if(buy==true)
        take=-prices[i]+help(prices,false,i+1,dp,fee);
    else
        take=(prices[i]-fee)+help(prices,true,i+1,dp,fee);
    notake=help(prices,buy,i+1,dp,fee);
    return dp[buy][i]=max(take,notake);
}
    int maxProfit(vector<int>& prices, int fee) {
        int buy=-1;
        int n=prices.size();
        vector<vector<int>>dp(2,vector<int>(n,-1));
        return help(prices,buy,0,dp,fee);
    }
};