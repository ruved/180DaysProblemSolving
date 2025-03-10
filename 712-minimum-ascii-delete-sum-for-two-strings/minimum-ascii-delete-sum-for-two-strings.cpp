class Solution {
public:
int help(string &s1, string &s2,int i,int j,vector<vector<int>>&dp){
    if(i<0||j<0){
        int sum=0;
        while(i>=0){
            sum+=int(s1[i--]);
        }
        while(j>=0){
            sum+=int(s2[j--]);
        }
        return sum;
    }
    if(dp[i][j]!=-1) return dp[i][j];

    if(s1[i]==s2[j])
        return dp[i][j]=help(s1,s2,i-1,j-1,dp);
    else
       return dp[i][j]=min(help(s1,s2,i-1,j,dp)+int(s1[i]),help(s1,s2,i,j-1,dp)+int(s2[j])); 
    
}
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return help(s1,s2,n-1,m-1,dp);
    }
};