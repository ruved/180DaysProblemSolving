class Solution {
public:
int help(vector<int>& nums,int i,int sum,vector<vector<int>>&dp){
        if(i<0){
            if(sum%3==0) return 0;
            return INT_MIN;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        int take=nums[i]+help(nums,i-1,(sum+nums[i])%3,dp);
        int notake=help(nums,i-1,sum,dp);
        return dp[i][sum]=max(take,notake);
}
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(3,-1));
        return help(nums,n-1,0,dp);
    }
};