class Solution {
public:
int helper(int ind , int n , vector<int>&nums, vector<int>&dp){
    if(ind >=n) return 0;
    if(nums[ind] == 0) return 1e9;
    if(dp[ind] != -1) return dp[ind];
    int temp = 1e9;
    for(int i = ind+1; i<=nums[ind]; i++){
        temp = min(temp , 1 + helper(i,n,nums,dp));
    }
    return dp[ind] = temp;
}
int minTaps(int n, vector<int>& ranges) {
      vector<int>v(n+1  , 0);
      for(int i=0;i<=n;i++){
        if(ranges[i] == 0) continue;
        int ind = max(0 , i-ranges[i]);
        int val = i+ranges[i];
        v[ind] = max(v[ind] , val);
      }

    vector<int>dp(n+2 , -1);
    int ans =  helper(0 , n , v,dp);
    return ans==1e9?-1:ans;
}
};