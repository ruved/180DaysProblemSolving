class Solution {
public:
bool help(vector<int>& nums,int i,int sum,vector<vector<int>>&dp){
    if(sum==0) return 1;
    if(i<0) return 0;
    if(dp[i][sum]!=-1) return dp[i][sum];
    bool take=0,notake=0;

    if(sum>=nums[i])
        take=help(nums,i-1,sum-nums[i],dp);
    notake=help(nums,i-1,sum,dp);
    return dp[i][sum]=max(take,notake);


}
    bool canPartition(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();++i)
            ans+=nums[i];
        vector<vector<int>>dp(nums.size(),vector<int>(ans+1,-1));
        if(ans%2!=0) return false;
        return help(nums,nums.size()-1,ans/2,dp);
    }
};