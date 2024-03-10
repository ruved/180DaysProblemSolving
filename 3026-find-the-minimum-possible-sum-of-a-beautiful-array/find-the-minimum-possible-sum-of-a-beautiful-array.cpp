class Solution {
public:
    int minimumPossibleSum(int n, int target) {
       
        int mod=1e9+7;
         int half = target/2;
        if( n <= half) return n*1LL*(n + 1)/2 ;
        long long ans= half*1LL*(half + 1)/2 + ( n - half )* 1LL* target +  ( n - half)*1LL* ( n - half - 1)/2;
        return ans%mod;
    }
};