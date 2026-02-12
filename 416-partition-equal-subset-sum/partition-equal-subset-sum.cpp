class Solution {
public:
int help(vector<int>& nums,int i,int sum, vector<vector<int>>&dp){
    if(i<0||sum==0) return sum==0;
    if(dp[i][sum]!=-1) return dp[i][sum];
    bool take=false;
    if(nums[i]<=sum)
        take=help(nums,i-1,sum-nums[i],dp);
    take|=help(nums,i-1,sum,dp);
    return dp[i][sum]=take;
}
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i:nums) sum+=i;
        if(sum&1) return false;
        // vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));
        // return help(nums,nums.size()-1,sum/2,dp);
        // vector<vector<bool>>dp(n,vector<bool>(sum/2+1,false));
        // for(int i=0;i<n;++i) dp[i][0]=true;
        // if(nums[0]<=sum/2)
        //     dp[0][nums[0]]=true;
       
        // for(int i=1;i<n;++i){
        //     for(int am=1;am<=sum/2;++am){
        //         if(nums[i]>am)
        //         dp[i][am]=dp[i-1][am];
        //         else
        //         dp[i][am]=dp[i-1][am]|dp[i-1][am-nums[i]];
        //     }
        // }
        // return dp[n-1][sum/2];
        vector<bool>dp(sum/2+1,false);
        dp[0]=true;
        // if(nums[0]<=(sum/2))
        //     dp[nums[0]]=true;
        
        for(int i=0;i<n;++i)
           for(int am = sum/2; am >= nums[i]; am--) {
                dp[am] = dp[am] || dp[am - nums[i]];
    }
            
        return dp[sum/2];
    }
};