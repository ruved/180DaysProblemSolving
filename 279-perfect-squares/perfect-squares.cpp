class Solution {
public:
    int numSquares(int n) {
        if(n<=1) return n;
        int l=sqrt(n);
        vector<int>prev(l+1),dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=l;++i) prev[i]=i*i;
        // int l=sqrt(n);
        // int res=INT_MAX;
        // for(int i=1;i<=l;++i){
        //     res=min(res,1+numSquares(n-i*i));
        // }
        // return res;
        int res=INT_MAX;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=sqrt(i);++j)
                    dp[i]=min(dp[i],1+dp[i-prev[j]]);
            cout<<dp[i]<<" ";
        }
        return dp[n];

    }
};