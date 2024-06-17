class Solution {
public:
int help(vector<int>& days, vector<int>& costs,int i,vector<int>&dp){
    if(i>=days.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    int a=costs[0]+help(days,costs,i+1,dp);
    int week=days[i]+7-1;
    int j=i;
    while(j<days.size()&&week>=days[j]){
        j++;
    }
    int b=costs[1]+help(days,costs,j,dp);
    int month=days[i]+30-1;
    j=i;
    while(j<days.size()&&month>=days[j]){
        j++;
    }
    int c=costs[2]+help(days,costs,j,dp);
    return dp[i]=min(min(a,b),c);
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size(),-1);
      return   help(days,costs,0,dp);
    }
};