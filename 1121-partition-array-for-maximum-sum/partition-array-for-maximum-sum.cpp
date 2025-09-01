class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,0);
        for(int i=0;i<n;++i){
            int mx=INT_MIN;
            for(int j=0;j<k&&(i-j)>=0;++j){
                mx=max(arr[i-j],mx);
                int prev = (i - j - 1 >= 0) ? dp[i - j - 1] : 0;   
                dp[i] = max(dp[i], prev + (j + 1) * mx);
            }
           // cout<<dp[i]<<"-";
        }
        return dp[n-1];
    }
};