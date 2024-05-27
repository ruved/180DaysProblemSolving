class Solution {
public:
int help(vector<int>& days, vector<int>& costs,int i,vector<int>&dp)
    {
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int d=0,w=0,m=0;
        d=costs[0]+help(days,costs,i-1,dp);
        int j=i-1;

        while(j>=0&&days[i]-7<days[j]){
            j--;
        }
        w=costs[1]+help(days,costs,j,dp);

         j=i-1;

        while(j>=0&&days[i]-30<days[j]){
            j--;
        }
        m=costs[2]+help(days,costs,j,dp);
    return dp[i]=min(d,min(w,m));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size()+1,-1);
        return help(days,costs,days.size()-1,dp);
    }
};