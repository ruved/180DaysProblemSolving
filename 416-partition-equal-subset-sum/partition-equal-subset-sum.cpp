class Solution {
public:
int help(vector<int>& nums,int i,int sum,vector<vector<int>>&dp){
    if(sum==0) return true;
    if(i<0) return false;
    if(dp[i][sum]!=-1) return dp[i][sum];
    int take=false,notake=false;
    if(sum>=nums[i]) 
        take=help(nums,i-1,sum-nums[i],dp);
    notake=help(nums,i-1,sum,dp);
    dp[i][sum]=take||notake;
    return dp[i][sum];
}
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();++i) sum+=nums[i];
        int n=nums.size();
        if(sum%2==1) return false;
        vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));
       if (help(nums,n-1,sum/2,dp)==1)
        return true;
       return false;
    }
};