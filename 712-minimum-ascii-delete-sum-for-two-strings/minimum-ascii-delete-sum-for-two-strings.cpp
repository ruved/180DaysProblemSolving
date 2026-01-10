class Solution {
public:
int help(string &s1, string &s2,int i ,int j,vector<vector<int>>&dp){
    if(i<0||j<0){
        int sum=0;
        while(j>=0){
            sum+=s2[j];
            j--;
        }
        while(i>=0){
            sum+=s1[i];
            i--;
        }
        return sum;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j])
        return dp[i][j]=help(s1,s2,i-1,j-1,dp);
    else{
        return dp[i][j]=min(s1[i]+help(s1,s2,i-1,j,dp),s2[j]+help(s1,s2,i,j-1,dp));
    }
}
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.length();
        int n=s2.length();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return help(s1,s2,m-1,n-1,dp);
    }
};