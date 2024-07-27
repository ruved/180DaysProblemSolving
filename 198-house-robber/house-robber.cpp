class Solution {
public:
int help(vector<int>& nums,int i,bool canRob,vector<vector<int>>&dp){
    if(i<0) return 0;

    if(dp[i][canRob]!=-1) return dp[i][canRob];
    int take=0,notake=0;
    if(canRob){
        take=nums[i]+help(nums,i-1,false,dp);
    }
    notake=help(nums,i-1,true,dp);

    return dp[i][canRob]=max(take,notake);
}
    int rob(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(2,-1));
        return  help(nums,nums.size()-1,true,dp);
    }
};