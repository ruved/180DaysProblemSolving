class Solution {
public:
int help(vector<int>& prices,int i,bool buy,vector<vector<int>>&dp){
    if(i>=prices.size()) return 0;

    if(dp[i][buy]!=-1) return dp[i][buy];
    int take=0,notake=0;
    if(buy)
        take = -prices[i]+help(prices,i+1,false,dp);
    else
        take = prices[i]+help(prices,i+2,true,dp);

    notake=help(prices,i+1,buy,dp);
    return dp[i][buy]=max(take,notake);
    
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
         
        vector<vector<int>>dp(n,vector<int>(2,-1));
        int ans= help(prices,0,true,dp);
        return ans<0?0:ans;
    }
};