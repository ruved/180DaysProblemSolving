class Solution {
public:
 
   int help(vector<int>& cost, vector<int>& time,int i,int walls,vector<vector<int>>&dp)
    {
        if(walls<=0)
            return 0; 
       
      if(i<0) return INT_MAX;
       
       // cout<<walls<<"-- ";
       
       if(dp[i][walls]!=-1) return dp[i][walls];
       
       int take=help(cost,time,i-1,walls-time[i]-1,dp);
       take=(take==INT_MAX)?INT_MAX:(cost[i]+take);
       int dontTake=help(cost,time,i-1,walls,dp);
       
       return dp[i][walls]=min(take,dontTake);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        // int ans=INT_MAX;
        int n=time.size()-1;
        vector<vector<int>>dp(n+1,vector<int>(n+2,-1));
        return help(cost,time,n,n+1,dp);
        //return ans;
    }
};
// [26,53,10,24,25,20,63,51] [10,20,24
// [1,1,1,1,2,2,2,1]         [1,2, ]
// (1,1) 3,3,2,2,2
