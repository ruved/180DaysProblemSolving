class Solution {
public:
int help(vector<int>& arr, int &difference,int prev,int i,vector<vector<int>>&dp){
        if(i>=arr.size()) return 0;
        
        if(dp[prev+1][i]!=INT_MIN) 
            return dp[prev+1][i];
        int take=0,notake=0;
        notake=help(arr,difference,prev,i+1,dp);
        if(prev==-1||((arr[i]-arr[prev])==difference)){
            take=1+help(arr,difference,i,i+1,dp);
        }
         int res=dp[prev+1][i]=max(take,notake);
         cout<<prev<<" "<<i<<" "<<res<<":";
         return dp[prev+1][i];
}
    int longestSubsequence(vector<int>& arr, int difference) {
         int n = arr.size();
        unordered_map<int, int> dp; 
        
        int ans = 1; 
        
        for (int i = 0; i < n; i++) {
            int num = arr[i];
            if (dp.find(num - difference) != dp.end()) {
                dp[num] = dp[num - difference] + 1;
            } else {
                dp[num] = 1;
            }
            
            ans = max(ans, dp[num]);
        }
        
        return ans;
    }
};