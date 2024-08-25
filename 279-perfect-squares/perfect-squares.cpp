class Solution {
public:
    int help(int n,vector<int>&tc,vector<int>&res){
        if(n==0) return 0;
        if(res[n]!=-1) return res[n];
        int rt=sqrt(n);
        int ans=INT_MAX;
        for(int i=1;i<=rt;++i)
            ans=min(ans,1+help(n-tc[i],tc,res));
        return res[n]=ans;
    }
    int numSquares(int n) {
        int si=sqrt(n);
        vector<int>dp(si+1,-1);
        for(int i=1;i*i<=n;++i)
            dp[i]=i*i;
            vector<int>res(n+1,-1);
        return help(n,dp,res);
    }
};

