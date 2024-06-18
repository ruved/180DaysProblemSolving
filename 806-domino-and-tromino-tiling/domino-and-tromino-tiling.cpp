class Solution {
public:
int dp[1001];
    int dp1[1001];
    int M = 1e9 + 7;
    long long int triminoSolve(int n) {
        
        if(n == 1) {
            return 1;
        }


        if(n <= 0) {
            return 0;
        }

        if(dp1[n] == -1) {
            return dp1[n] = (triminoSolve(n-1) + dominoSolve(n-1))%M;
        }
        
        return dp1[n];
    }

    long long int dominoSolve(int n) {
        if(n==0) {
            return 1;
        }
        if(n<0) {
            return 0;
        }

        if(dp[n] == -1) {
            return dp[n] = ((dominoSolve(n-1) + dominoSolve(n-2))%M + 2 * triminoSolve(n-2)%M)%M;
        }
        return dp[n];
    }
    int numTilings(int n) {
        memset(dp,-1,sizeof(dp));
        memset(dp1,-1,sizeof(dp));
        return dominoSolve(n);
    }
};