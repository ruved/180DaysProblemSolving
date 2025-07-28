class Solution {
public:
int help(vector<int>& nums,int i,int sum,int &mx, vector<vector<int>>&dp){
    if(i<0&&(sum==mx)) return 1;
    if(i<0) return 0;
    if(dp[i][sum]!=-1) return dp[i][sum];
    int t=help(nums,i-1,sum|nums[i],mx,dp);
    int nt=help(nums,i-1,sum,mx,dp);
    return dp[i][sum]=t+nt; 
}
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;++i)
            sum|=nums[i];

        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return help(nums,n-1,0,sum,dp);
    }
};