class Solution {
public:
int help(vector<int>& arr, int &k,int i,vector<int>&dp){
    if(i<0) return 0;
    if(dp[i]!=-1) return dp[i];
    int mx=-1;
    int ans=0;
    for(int j=i;j>(i-k)&&(j>=0);--j){
        mx=max(mx,arr[j]);
        ans=max(ans,mx*(i-j+1)+help(arr,k,j-1,dp));
    }
    return dp[i]=ans;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,-1);
        return help(arr,k,n-1,dp);
    }
};

