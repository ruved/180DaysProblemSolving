class Solution {
public:
int help(vector<int>& prices,int i,bool buy,int k,vector<vector<vector<int>>>&dp){
    if(i==prices.size()||k==0) return 0;

    if(dp[i][k][buy]!=-1) return dp[i][k][buy];
    int take=0,notake=0;
    if(buy)
        take = -prices[i]+help(prices,i+1,false,k,dp);
    else
        take = prices[i]+help(prices,i+1,true,k-1,dp);

    notake=help(prices,i+1,buy,k,dp);
    return dp[i][k][buy]=max(take,notake);
    
}
    int maxProfit(vector<int>& prices) {
         int n=prices.size();
         int k=2;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(3,vector<int>(2,-1)));
        int ans= help(prices,0,true,k,dp);
        return ans<0?0:ans;
    }
};