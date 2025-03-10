class Solution {
public:
bool pal(string &s){
    int i=0,j=s.length()-1;
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++,j--;
    }
    return true;
}
int help(string &s,int i,vector<int>&dp){
    if(i<0) return 0;
    if(dp[i]!=-1) return dp[i];
    string sub="";
    int ans=INT_MAX;
    for(int j=i;j>=0;--j){
        sub.push_back(s[j]);
        if(pal(sub)){
            ans=min(ans,1+help(s,j-1,dp));
        }
    }
    return dp[i]=ans;
}
    int minCut(string s) {
        int n=s.length();
        vector<int>dp(n,-1);
        return help(s,n-1,dp)-1;
    }
};