class Solution {
public:
int help(vector<pair<int,int>>&vc,int i,int m,int n,vector<vector<vector<int>>>&dp){
    if(i<0) return 0;
    if(dp[i][m][n]!=-1) return dp[i][m][n];
    int ans=0;
    if(vc[i].first<=m&&vc[i].second<=n)
        ans=1+help(vc,i-1,m-vc[i].first,n-vc[i].second,dp);
    ans=max(ans,help(vc,i-1,m,n,dp));
    return dp[i][m][n]=ans;
}
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>vc(strs.size());
        for(int i=0;i<strs.size();++i){
            int x=0;
            for(int j=0;j<strs[i].size();++j)
                if(strs[i][j]=='0') x++;
            vc[i]=make_pair(x,strs[i].size()-x);
        }
        vector<vector<vector<int>>>dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return help(vc,strs.size()-1,m,n,dp);
    }
};