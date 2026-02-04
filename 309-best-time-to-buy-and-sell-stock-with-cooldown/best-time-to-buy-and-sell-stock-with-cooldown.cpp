class Solution {
public:
int help(vector<int>& prices,int i,bool turn){
    if(i>=prices.size()) return 0;
    int res=0;
    if(turn)
        res=-prices[i]+help(prices,i+1,!turn);
    else
        res=prices[i]+help(prices,i+2,!turn);
    res=max(res,help(prices,i+1,turn));

    return res;

}
    int maxProfit(vector<int>& prices) {
        // return help(prices,0,true);
        int n=prices.size();
        vector<vector<int>>dp(3,vector<int>(2,0));
        
        for(int i=n-1;i>=0;--i){
               dp[i%3][1]=max(dp[(i+1)%3][1],-prices[i]+dp[(i+1)%3][0]);
               dp[i%3][0]=max(dp[(i+1)%3][0],prices[i]+dp[(i+2)%3][1]);
        }
        return dp[0][1];
    }
};