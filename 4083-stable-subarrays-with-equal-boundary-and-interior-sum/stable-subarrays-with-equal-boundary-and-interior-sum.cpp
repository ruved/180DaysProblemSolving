class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int n = capacity.size();
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + capacity[i];

        unordered_map<int, unordered_map<long long, int>> mp;
        mp.reserve(n * 2);
        long long ans = 0;

        for (int r = 0; r < n; ++r) {
            // insert l = r-2 into map so mp contains only l <= r-2 (ensures length >= 3)
            if (r - 2 >= 0) {
                int l = r - 2;
                mp[capacity[l]][ pref[l + 1] ]++;
            }

            long long target = pref[r] - capacity[r]; // this must equal pref[l+1]
            if (mp.count(capacity[r])) {
                auto &inner = mp[capacity[r]];
                if (inner.count(target)) ans += inner[target];
            }
        }
        return ans;
    }
};
