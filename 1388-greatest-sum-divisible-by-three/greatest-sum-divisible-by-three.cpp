class Solution {
public:
int help(vector<int>& nums,int i,int rem,vector<vector<int>>&dp){
    if(i<0) {return (rem==0)?0:INT_MIN;}
    if(dp[i][rem]!=-1) return dp[i][rem];
    int take=help(nums,i-1,(rem+nums[i])%3,dp);
    if(take!=INT_MIN) take+=nums[i];
    int notake=help(nums,i-1,rem,dp);
    return dp[i][rem]=max(take,notake);
}
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>>dp(n,vector<int>(3,-1));
        // return help(nums,n-1,0,dp);
        vector<int>prev(3,INT_MIN);
        vector<int>cur(3,0);
        prev[0]=0;
        for(int i=1;i<=n;++i){
            for(int rem=0;rem<3;++rem){
                int prevrem=(rem - nums[i-1] % 3 + 3) % 3;
                int take=prev[prevrem];
                if(take!=INT_MIN) take+=nums[i-1];
                int notake=prev[rem];//help(nums,i-1,rem,dp);
                cur[rem]=max(take,notake);
            } 
            prev=cur;
        }
        return prev[0];
    }
};