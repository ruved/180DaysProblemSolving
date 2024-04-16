class Solution {
public:
int help(vector<int>& nums,int ind,vector<int>&dp)
{
    
    if(ind>=nums.size()-1) return true;

    if(nums[ind]==0) return false;
    if(dp[ind]!=-1) return dp[ind];
    bool ans=false;
    for(int j=1;j<=nums[ind];++j)
    {
         ans|=help(nums,ind+j,dp);
         if(ans) break;
    }
       
    return dp[ind]=ans;
}
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
      return  help(nums,0,dp);
    }
};