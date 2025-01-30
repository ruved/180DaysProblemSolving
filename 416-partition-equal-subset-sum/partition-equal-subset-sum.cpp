class Solution {
public:
bool help(vector<int>& nums,int i,int sum,vector<vector<int>>&dp){
    if(sum==0) return true;
    if(i<0) return false;

    if(dp[i][sum]!=-1) return dp[i][sum];
    
    bool take=false;
    if(nums[i]<=sum)    
        take=help(nums,i-1,sum-nums[i],dp);
    bool notake=help(nums,i-1,sum,dp);

    return dp[i][sum]=notake||take;
}
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        
        for(int i=0;i<nums.size();++i) sum+=nums[i];
        if(sum%2==1) return false;
        vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));
        return help(nums,nums.size()-1,sum/2,dp);
    }
};