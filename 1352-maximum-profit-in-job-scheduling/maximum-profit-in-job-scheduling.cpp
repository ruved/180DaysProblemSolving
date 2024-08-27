class Solution {
public:
   int help(vector<int>& startTime, vector<int>& endTime, vector<int>& profit,int i,vector<int>&dp)
    {
       if(i==startTime.size())
           return 0;
       
       if(dp[i]!=-1) return dp[i];
       //take condition
       int take=0,notTake=0;
       int nextIndex = lower_bound(startTime.begin(), startTime.end(), endTime[i]) - startTime.begin();
        
      take=profit[i]+help(startTime,endTime,profit,nextIndex,dp);
       
       notTake=help(startTime,endTime,profit,i+1,dp);
       return dp[i]=max(dp[i],max(take,notTake));
       
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        vector<pair<int,pair<int,int>>>p;
        for(int i=0;i<startTime.size();++i)
            p.push_back({startTime[i],{endTime[i],profit[i]}});
        sort(p.begin(),p.end());
        int sum=0;
         for(int i=0;i<startTime.size();++i)
         {
             pair<int,pair<int,int>>mp=p[i];
             startTime[i]=mp.first;
             endTime[i]=mp.second.first;
             profit[i]=mp.second.second;
             // sum+=profit[i];
             // cout<<startTime[i]<<" "<<endTime[i]<<" "<<profit[i]<<"::";
         }
        int prev=-1;
        int temp=0,ans=0;
      vector<int>dp(startTime.size()+1,-1);
        return help(startTime,endTime,profit,0,dp);
    }
      
};