class Solution {
public:

bool dfs(int mask, int curr, int target, vector<int>& nums, vector<int>& memo) {

        int n = nums.size();

        if(mask == (1<<n) - 1)
            return true;

        if(memo[mask] != -1)
            return memo[mask];

        for(int i = 0; i < n; i++) {

            if(mask & (1<<i)) continue;

            if(curr + nums[i] > target) continue;

            int nextMask = mask | (1<<i);

            int nextSum = (curr + nums[i]) % target;

            if(dfs(nextMask, nextSum, target, nums, memo))
                return memo[mask] = true;
        }

        return memo[mask] = false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum % k) return false;

        int target = sum / k;

        sort(nums.rbegin(), nums.rend());

        vector<int> memo(1 << nums.size(), -1);

        return dfs(0, 0, target, nums, memo);
    }
};