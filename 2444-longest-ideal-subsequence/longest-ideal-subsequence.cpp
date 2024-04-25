class Solution {
public:
int help(string &s, int &k,int i,vector<vector<int>>&dp,char prev){
    
    if(i<0) return 0;
    
    if(dp[i][prev-'a']!=-1) return dp[i][prev-'a'];
    int minclude=0,mexclude=0;
    
    if((abs(s[i]-prev)<=k)||prev=='{'){
        int temp=1+help(s,k,i-1,dp,s[i]);
        minclude=max(minclude,temp);
    }
    mexclude=help(s,k,i-1,dp,prev);

    return dp[i][prev-'a']=max(minclude,mexclude);
}
    int longestIdealString(string s, int k) {
        vector<vector<int>>dp(s.size()+1,vector<int>(27,-1));
        return help(s,k,s.size()-1,dp,'{');
    }
};