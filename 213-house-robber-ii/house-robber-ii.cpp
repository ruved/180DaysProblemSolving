class Solution {
public:
int help(vector<int>& nums,int i,int &end,vector<int>&dp){
    if(i<end) return 0;
    if(dp[i]!=-1) return dp[i];
    return dp[i]=max(nums[i]+help(nums,i-2,end,dp),help(nums,i-1,end,dp));
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>dp(n,-1);
        int end=0;
        int end1=1;
        int case1 = help(nums, n - 2, end, dp);

        // reset dp
        fill(dp.begin(), dp.end(), -1);

        int case2 = help(nums, n - 1, end1, dp);

        return max(case1, case2);
    }
};