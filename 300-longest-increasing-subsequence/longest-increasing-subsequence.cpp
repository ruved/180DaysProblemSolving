class Solution {
public:
int help(vector<int>& nums,int i,int prev,vector<vector<int>>&dp){
    if(i==nums.size()) return 0;
    if(dp[prev+1][i]!=-1) return dp[prev+1][i];
    int take=0;
    if(prev==-1||nums[prev]<nums[i])
    take=1+help(nums,i+1,i,dp);
    int notake=help( nums,i+1,prev,dp);
    return dp[prev+1][i]=max(take,notake);
}   
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n,0));
        // return help(nums,0,-1,dp);
        dp[0]={1};
        for(int i=0;i<n-1;++i)
            dp[i+1][n-1]=nums[i]<nums[n-1]?1:0;

        for(int i=n-2;i>=0;--i){
            for(int prev=i-1;prev>=-1;--prev){
                int take=0;
                if(prev==-1||nums[prev]<nums[i])
                    take=1+dp[i+1][i+1];//help(nums,i+1,i,dp);
                int notake=dp[prev+1][i+1];//help(nums,i+1,prev,dp);
                dp[prev+1][i]=max(take,notake);
            }
        }
        return dp[0][0];
    }
};