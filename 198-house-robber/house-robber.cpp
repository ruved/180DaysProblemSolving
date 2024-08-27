class Solution {
public:
int help(vector<int>& nums,int i,vector<int>&dp){
    if(i<0) return 0;
    if(dp[i]!=-1) return dp[i];
    int take=nums[i]+help(nums,i-2,dp);
    int notake=help(nums,i-1,dp);
    return dp[i]=max(take,notake);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return help(nums,n-1,dp);
    }
};