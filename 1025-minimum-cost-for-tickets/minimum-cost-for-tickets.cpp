class Solution {
public:
int help(vector<int>& days, vector<int>& costs,int i,vector<int>&dp){
    if(i<0) return 0;

    if(dp[i]!=-1) return dp[i];

    int day1=costs[0]+help(days,costs,i-1,dp);
    
    int j=i-1;
    while(j>=0&&days[j]>days[i]-7){
        j--;
    }
    int day7=costs[1]+help(days,costs,j,dp);

     j=i-1;
    while(j>=0&&days[j]>days[i]-30){
        j--;
    }
    int day30=costs[2]+help(days,costs,j,dp);
    return dp[i]=min(min(day1,day7),day30);
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
       int n=days.size();
       vector<int>dp(n,0);
    //    return  help(days,costs,n-1,dp); 
        dp[0]=costs[0];
        // if(days[0]>=7)
        dp[0]=min(dp[0],costs[1]);
        // if(days[0]>=30)
        dp[0]=min(dp[0],costs[2]);
        for(int i=1;i<n;++i){
            int day1=costs[0]+dp[i-1];
            int j=i-1;
            while(j>=0&&days[j]>days[i]-7){
                j--;
            }
            int day7=costs[1]+(j>=0?dp[j]:0);

            j=i-1;
            while(j>=0&&days[j]>days[i]-30){
                j--;
            }
            int day30=costs[2]+(j>=0?dp[j]:0);
            dp[i]=min(min(day1,day7),day30);
        }
        return dp[n-1];
    }
};