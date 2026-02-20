class Solution {
public:
int mod=1e9+7;
int help(string &s,int i,vector<int>&dp){
    if(i<0) return 0;
    if(dp[i]!=-1) return dp[i];
    unsigned int ans=0;
    for(int j=i-1;j>=0;--j){
        if(s[j]!=s[i]){
                ans+=1+help(s,j-1,dp);
                ans%=mod;
        }
    }
    return dp[i]=ans;
}
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        
        long long total = 1;  // counts empty subsequence
        vector<long long> last(26, 0);  // stores previous contribution
        
        for(char c : s) {
            long long newTotal = (2 * total % MOD - last[c - 'a'] + MOD) % MOD;
            last[c - 'a'] = total;
            total = newTotal;
        }
        
        return (total - 1 + MOD) % MOD; // remove empty subsequence
            
    }
};