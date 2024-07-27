class Solution {
public:
int help(vector<int>& prices,int i,bool buy,vector<vector<int>>&dp){
    if(i==prices.size()) return -1;

    if(dp[i][buy]!=-1) return dp[i][buy];
    int take=0,notake=0;
    if(buy)
        take = -prices[i]+help(prices,i,false,dp);
    else
        take = prices[i];

    notake=help(prices,i+1,buy,dp);
    return dp[i][buy]=max(take,notake);
    
}
// -1=not bought
// bought=i index
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return help(prices,0,true,dp);
    }
};

// buy day=0,1,2,3,
// sell day =later than buy