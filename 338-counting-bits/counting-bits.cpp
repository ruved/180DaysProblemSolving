class Solution {
public:
    vector<int> countBits(int n) {
      
        vector<int>dp(n+1);
       dp[0]=0;
       if(n==0) return dp;
       dp[1]=1;
       if(n==1) return dp;
        int count=1;
        int i=2;
        while(i<=n){
            dp[i]=1;
            if(i==n) break;
            int st=pow(2,count);
            int en=pow(2,count+1);
            while(i<=n&&i<en){
                dp[i]=dp[st]+dp[i-st];
                i++;
            }
            
            count++;
        }
        return dp;
    }
};