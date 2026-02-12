class Solution {
public:
int help(vector<int>& nums,int prev,bool pos,vector<vector<int>>&dp){
    if(prev<=0) return prev;
    if(dp[prev][pos]!=-1) return dp[prev][pos];
     int len=0;
    for(int j=prev-1;j>=0;--j){
        if(pos==((nums[prev]-nums[j])<0)&&nums[prev]!=nums[j])
            len=max(len,1+help(nums,j,!pos,dp));
    }
   
    return dp[prev][pos]=len;

}
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        int l=max(help(nums,n-1,true,dp),help(nums,n-1,false,dp));
        return l+1;
    }
};