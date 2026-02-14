class Solution {
public:
int help(vector<int>& days, vector<int>& costs,int i,vector<int>&dp){
    if(i<0) return 0;

    if(dp[i]!=-1) return dp[i];
    
    int day=costs[0]+help(days,costs,i-1,dp);
    int j=i;
    while(j>=0&&days[i]-7<days[j])
        j--;
    int week=costs[1]+help(days,costs,j,dp);
     j=i;
    while(j>=0&&days[i]-30<days[j])
        j--;
    int month=costs[2]+help(days,costs,j,dp);
    return dp[i]=min(min(day,week),month);
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n,0);
        // return help(days,costs,n-1,dp);
        for(int i=0;i<n;++i){
           int cost1 = costs[0] + (i > 0 ? dp[i-1] : 0);
            
            // 7-day pass
            int idx7 = lower_bound(days.begin(), days.end(), days[i] - 6) - days.begin();
            int cost7 = costs[1] + (idx7 > 0 ? dp[idx7 - 1] : 0);
            
            // 30-day pass
            int idx30 = lower_bound(days.begin(), days.end(), days[i] - 29) - days.begin();
            int cost30 = costs[2] + (idx30 > 0 ? dp[idx30 - 1] : 0);
            
            dp[i] = min({cost1, cost7, cost30});
        }
        return dp[n-1];
    }
};