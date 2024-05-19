class Solution {
public:
array<int, 10001> dp;
    int racecar(int target) {
        if ( dp[target] > 0 ) { return dp[target]; }

        int expo = floor(log2(target)) + 1;
        if ( 1 << expo  ==  (target + 1) ) {
            dp[target] = expo;
        } else {
            dp[target] = expo + 1 + racecar((1 << expo) - 1 - target);
            for ( int e = 0; e < expo - 1; e++ ) {
                dp[target] = min ( dp[target] , racecar(target - (1 << (expo - 1) ) + (1 << e)) + 1 + e + expo );
            }
        }

        return dp[target];
    }
};