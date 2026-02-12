class Solution {
public:
int help(vector<int>& nums,int i,int sum, vector<vector<int>>&dp){
    if(i<0||sum==0) return sum==0;
    if(dp[i][sum]!=-1) return dp[i][sum];
    bool take=false;
    if(nums[i]<=sum)
        take=help(nums,i-1,sum-nums[i],dp);
    take|=help(nums,i-1,sum,dp);
    return dp[i][sum]=take;
}
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i:nums) sum+=i;
        if(sum&1) return false;
        vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));
        return help(nums,nums.size()-1,sum/2,dp);
    }
};