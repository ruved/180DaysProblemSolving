class Solution {
public:
int help(vector<int>& nums,int i,vector<int>&dp){
    if(i<0) return 0;
    if(dp[i]!=-1) return dp[i];
    return dp[i]=max(nums[i]+help(nums,i-2,dp),help(nums,i-1,dp));
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return help(nums,n-1,dp);
    }
};