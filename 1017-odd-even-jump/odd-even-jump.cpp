class Solution {
public:

    int oddEvenJumps(vector<int>& arr) {
    int goodIndices;
        vector<pair<bool, bool>> dp(arr.size(), {false, false});
        map<int, int> seen;
        map<int, int>::iterator closest;

        dp.back().first = true;
        dp.back().second = true;
        goodIndices = 1;

        seen[arr.back()] = arr.size() - 1;

        for (int i = arr.size() - 2; i > -1; --i)
        {
            closest = seen.lower_bound(arr[i]);

            if (closest != seen.end() && closest->first == arr[i])
            {
                dp[i].first = dp[closest->second].second;
                dp[i].second = dp[closest->second].first;
            }
            else
            {
                dp[i].first = ((closest != seen.end()) ? dp[closest->second].second : false);
                if (closest == seen.begin())
                    dp[i].second = false;
                else
                {
                    --closest;
                    dp[i].second = dp[closest->second].first;
                }
            }
            
            if (dp[i].first) 
                ++goodIndices;

            seen[arr[i]] = i;
        }

        return goodIndices;
    }
};