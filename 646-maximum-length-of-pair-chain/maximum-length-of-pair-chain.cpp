class Solution {
public:
int help(vector<vector<int>>& pairs,int j,vector<int>&dp){
    if(j==0) return 1;
    if(dp[j]!=-1) return dp[j];
    int res=1;
    for(int i=0;i<j;++i){
        if(pairs[i][1]<pairs[j][0])
            res=max(res,1+help(pairs,i,dp));
    }
    return dp[j]=res;
}
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int j=pairs.size();

        vector<int>dp(j,-1);
        return help(pairs,j-1,dp);
    }
};

