class Solution {
public:
int help(vector<int>& arr, int &diff,int prev,vector<int>&dp){
    
    if(dp[prev] != -1) return dp[prev];
    int ans=1;
    for(int j=prev-1;j>=0;--j){
        if(arr[prev]-arr[j]==diff)
        ans=max(ans,1+help(arr,diff,j,dp));
    }
    return dp[prev]=ans;

}
    int longestSubsequence(vector<int>& arr, int difference) {
        // int n = arr.size();
        // vector<int> dp(n, -1);
        // int ans = 1;

        // for(int i = 0; i < n; i++) {
        //     ans = max(ans, help(arr, difference, i, dp));
        // }

        // return ans;
        unordered_map<int,int> dp;
        int ans = 1;
        
        for(int x : arr) {
            dp[x] = dp[x - difference] + 1;
            ans = max(ans, dp[x]);
        }
        
        return ans;
        
    }
};