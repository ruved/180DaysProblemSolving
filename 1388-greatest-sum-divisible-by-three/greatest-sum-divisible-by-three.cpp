class Solution {
public:
int help(vector<int>& nums,int i,int rem,vector<vector<int>>&dp){
    if(i<0) {return (rem==0)?0:INT_MAX;}
    if(dp[i][rem]!=-1) return dp[i][rem];
    int take=help(nums,i-1,(rem+nums[i])%3,dp);
    if(take!=INT_MAX) take+=nums[i];
    int notake=help(nums,i-1,rem,dp);
    int res=0;
    if(take==INT_MAX&&notake==INT_MAX) res=INT_MAX;
    else if(take==INT_MAX||notake==INT_MAX) res=min(take,notake);
    else
        res=max(take,notake);
    return dp[i][rem]=res;
}
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(3,-1));
        return help(nums,n-1,0,dp);
    }
};