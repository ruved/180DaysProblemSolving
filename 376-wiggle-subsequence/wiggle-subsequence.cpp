class Solution {
public:
int help(vector<int>& nums,int i,bool pos,vector<vector<int>>&dp){
    if(i<0) return 0;
    if(dp[i][pos]!=-1) return dp[i][pos];
    int notake=help(nums,i-1,pos,dp);
    int take=1;
    for(int j=i-1;j>=0;--j){
        if((pos&&nums[i]-nums[j]>0)||(!pos&&nums[i]-nums[j]<0))
            take=max(take,1+help(nums,j,!pos,dp));
    }
    return dp[i][pos]=max(take,notake);
}
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return max(help(nums,n-1,true,dp),help(nums,n-1,false,dp));
    }
};