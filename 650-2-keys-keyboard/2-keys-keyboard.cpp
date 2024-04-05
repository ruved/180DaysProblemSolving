class Solution {
public:
int help(int &n,int copy,int v,vector<vector<int>>&dp)
{
    if(v==n) return 0;
    if(v>n) return INT_MAX;

    if(dp[v][copy]!=-1) return dp[v][copy];
    int take=INT_MAX,nottake=INT_MAX;
    if(v!=copy)
    nottake=help(n,v,v,dp);
    
    take=help(n,copy,v+copy,dp);
    int val=min(take,nottake);
    return dp[v][copy]=val!=INT_MAX?val+1:val;
}
    int minSteps(int n) {
    if(n==1)  return 0;
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    int copy=1; 
    return 1+help(n,copy,1,dp); 
    }
};