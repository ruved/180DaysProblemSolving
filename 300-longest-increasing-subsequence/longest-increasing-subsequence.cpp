class Solution {
public:
    int help(vector<int>& nums,int i,int prev,vector<vector<int>>&dp){
        if(i>=nums.size()) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int take=0,notake=0;
        if(prev!=-1&&nums[prev]<nums[i])
            take=1+help(nums,i+1,i,dp);
        if(prev==-1)
            take=1+help(nums,i+1,i,dp);
        notake=help(nums,i+1,prev,dp);
        return dp[i][prev+1]=max(take,notake);

    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        return help(nums,0,-1,dp);
    }
};