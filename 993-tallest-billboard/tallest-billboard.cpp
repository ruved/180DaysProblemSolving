class Solution {
public:
int n;
    vector<vector<int>> dp;
    vector<int> rods;
    
    int solve(int i, int diff) {
        if (i == n) {
            return diff == 0 ? 0 : -1e9;  // valid only if balanced
        }
        
        if (dp[i][diff] != -1)
            return dp[i][diff];
        
        int r = rods[i];
        
        // 1️⃣ Skip this rod
        int ans = solve(i + 1, diff);
        
        // 2️⃣ Add rod to taller side
        ans = max(ans, solve(i + 1, diff + r));
        
        // 3️⃣ Add rod to shorter side
        int newDiff = abs(diff - r);
        int gain = min(diff, r);
        
        ans = max(ans, gain + solve(i + 1, newDiff));
        
        return dp[i][diff] = ans;
    }
    
    int tallestBillboard(vector<int>& rodsInput) {
        rods = rodsInput;
        n = rods.size();
        
        int total = accumulate(rods.begin(), rods.end(), 0);
        
        dp.assign(n, vector<int>(total + 1, -1));
        
        return solve(0, 0);
    }
};