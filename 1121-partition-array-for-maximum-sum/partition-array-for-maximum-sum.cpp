class Solution {
public:
int help(vector<int>& arr, int &k,int i,vector<int>&dp){
    if(i<0) return 0;
    if(dp[i]!=-1) return dp[i];
    int mx=arr[i];
    int ans=0;
    for(int j=i;(j>i-k)&&j>=0;--j){
        mx=max(mx,arr[j]);
        ans=max(ans,mx*(i-j+1)+help(arr,k,j-1,dp));

    }
    return dp[i]=ans;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        // vector<int>dp(n,-1);
        // return help(arr,k,n-1,dp);
        vector<int>dp(n+1,0);
        dp[0]=0;
        for(int i=1;i<=n;++i){
            int mx=arr[i-1];
            for(int j=i;(j>i-k)&&j>=1;--j){
                mx=max(mx,arr[j-1]);
                dp[i]=max(dp[i],mx*(i-j+1)+dp[j-1]);//help(arr,k,j-1,dp));
            }
        }
        return dp[n];
    }
        
};