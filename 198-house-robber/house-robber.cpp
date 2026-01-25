class Solution {
public:
int help(vector<int>& nums,int i,int &end,vector<int>&dp){
    if(i<end) return 0;
    if(dp[i]!=-1) return dp[i];
    return dp[i]=max(nums[i]+help(nums,i-2,end,dp),help(nums,i-1,end,dp));
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(3,0);
        // return max(help(nums,n-1,1,dp),help(nums,n-2,0,dp));
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);

        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        // 2,0,1->3%3,1,2
        for(int i=2;i<n;++i)
            dp[i%3]=max(nums[i]+dp[(i-2)%3],dp[(i-1)%3]);
        return dp[(n-1)%3];


    }
};