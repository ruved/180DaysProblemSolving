#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        if (n == 0) return 0;
        sort(nums.begin(), nums.end());

        unordered_map<int,int> freq;
        freq.reserve(n*2);
        for (int x : nums) ++freq[x];

        vector<int> uniq;
        uniq.reserve(freq.size());
        for (auto &p : freq) uniq.push_back(p.first);
        sort(uniq.begin(), uniq.end());

        int ans = 0;
        for (int v : uniq) {
            int L = int(lower_bound(nums.begin(), nums.end(), v - k) - nums.begin());
            int R = int(upper_bound(nums.begin(), nums.end(), v + k) - nums.begin());
            int candidate = R - L;                     // elements that can reach v
            int achievable = min(candidate, freq[v] + numOperations);
            ans = max(ans, achievable);
        }

        int l = 0, maxcand = 0;
        for (int r = 0; r < n; ++r) {
            while (nums[r] - nums[l] > 2LL * k) ++l;
            maxcand = max(maxcand, r - l + 1);
        }
        ans = max(ans, min(maxcand, numOperations));

        return ans;
    }
};
