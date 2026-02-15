class Solution {
public:
int help(vector<int>& stoneValue,int i,vector<int>&dp){
    if(i>=stoneValue.size()) return 0;
    
    if(dp[i] != INT_MIN) return dp[i];
    
    int n = stoneValue.size();
        int takeSum = 0;
        int best = INT_MIN;

        for(int k = 0; k < 3 && i + k < n; k++) {
            takeSum += stoneValue[i + k];
            best = max(best, takeSum - help(stoneValue, i + k + 1, dp));
        }

        return dp[i] = best;
}
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int>dp(n,INT_MIN);
        int ans=help(stoneValue,0,dp);
        if(ans>0) return "Alice";
        else if(ans==0) return "Tie";
        else return "Bob";
    }
};