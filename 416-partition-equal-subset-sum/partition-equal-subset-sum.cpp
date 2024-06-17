class Solution {
public:
int help(vector<int>& nums,int i,int sum,vector<vector<int>>&dp){
    if(i<0&&sum!=0) return  false;
    if(i<0&&sum==0) return true;
    if(dp[i][sum]!=-1) return dp[i][sum];

    bool take=false,notake=false;
    if(nums[i]<=sum) 
        take=help(nums,i-1,sum-nums[i],dp);
    notake=help(nums,i-1,sum,dp);
    return dp[i][sum]=take||notake;

}
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();++i){
            sum+=nums[i];
        }
        if(sum%2==1) return false;

        vector<vector<int>>dp(nums.size(),vector<int>(sum/2+1,-1));
        return help(nums,nums.size()-1,sum/2,dp);
    }
};