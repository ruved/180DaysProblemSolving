class Solution {
public:
    vector<int> countBits(int n) {
         vector<int> dp(n+1, 0);
        
        int power = 1;
        
        while(power <= n) {
            
            for(int i = 0; i < power && power + i <= n; i++) {
                dp[power + i] = 1 + dp[i];
            }
            
            power <<= 1;
        }
        
        return dp;
    }
};