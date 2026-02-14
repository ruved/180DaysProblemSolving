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
        vector<int>dp(n,-1);
        return help(days,costs,n-1,dp);
    }
};