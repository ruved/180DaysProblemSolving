class Solution {
public:
    int mod =1e9+7;
    int help(vector<vector<int>>&types,int i,int target,vector<vector<int>>&dp)
    { 
        if(target==0) return 1;
        if(i<0) return 0;
        if(dp[i][target]!=-1) return dp[i][target];
        long long res=0;
       for(int j=0;j<=types[i][0];++j)
       {
           if(target-types[i][1]*j>=0)
               res+=help(types,i-1,target-types[i][1]*j,dp);
       }
    
        return dp[i][target]=res%mod;
        
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        vector<vector<int>>dp(types.size()+1,vector<int>(target+1,-1));
        return help(types,types.size()-1,target,dp);
    }
};