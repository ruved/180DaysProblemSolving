class Solution {
public:
bool help(int mask,int curr,int &target,vector<int>& matchsticks,vector<int>&dp){
    if(mask == (1<<matchsticks.size())-1)
    return curr == 0;
    if(dp[mask]!=-1) return dp[mask];
    for(int i=0;i<matchsticks.size();++i){
        if(mask&(1<<i)) continue;
        if(curr+matchsticks[i]>target) continue;
        int next=(curr+matchsticks[i])%target;
        if(help(mask | (1<<i), next, target, matchsticks, dp))
            return dp[mask] = true;
    }
    return dp[mask] = false;
}
    bool makesquare(vector<int>& matchsticks) {
        int n=matchsticks.size();
        int sum=0;
        for(int i=0;i<n;++i) sum+=matchsticks[i];
        if(sum%4) return false;
        int target=sum/4;
        int N=1<<n;
        vector<int>dp(N,-1);
       return  help(0,0,target,matchsticks,dp);
    }
};