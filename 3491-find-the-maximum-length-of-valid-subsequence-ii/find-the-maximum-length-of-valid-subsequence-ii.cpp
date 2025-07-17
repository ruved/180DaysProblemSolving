class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int maxlen = 2, n = nums.size();

        vector< unordered_map<int,int> > dp(n);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                int rem = (nums[i] + nums[j]) % k;
                if(dp[j].find(rem) != dp[j].end())
                {
                    dp[i][rem] = dp[j][rem] + 1;
                }
                else
                {
                    dp[i][rem] = 2;
                }
                maxlen = max(maxlen, dp[i][rem]);
            }
        }
        return maxlen; 
    }
};