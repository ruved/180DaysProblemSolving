#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        int m = k - 2; // We need to pick i1, then m more elements from the window
        
        long long currentWindowSum = 0;
        multiset<int> low, high;

        // Helper to add an element to the two-multiset system
        auto add = [&](int val) {
            low.insert(val);
            currentWindowSum += val;
            if (low.size() > m) {
                int toHigh = *low.rbegin();
                currentWindowSum -= toHigh;
                high.insert(toHigh);
                low.erase(prev(low.end()));
            }
        };

        // Helper to remove an element (O(log dist))
        auto remove = [&](int val) {
            auto it = low.find(val);
            if (it != low.end()) {
                currentWindowSum -= val;
                low.erase(it);
            } else {
                high.erase(high.find(val));
            }
            // If low is now too small, pull from high
            if (low.size() < m && !high.empty()) {
                int fromHigh = *high.begin();
                currentWindowSum += fromHigh;
                low.insert(fromHigh);
                high.erase(high.begin());
            }
        };

        // 1. Initialize the window for the first possible i1 (which is index 1)
        // The available range for the other k-2 elements is [2, 1 + dist]
        for (int i = 2; i <= 1 + dist && i < n; i++) {
            add(nums[i]);
        }

        long long minTotalCost = nums[0] + (long long)nums[1] + currentWindowSum;

        // 2. Slide the window for i1 = 2 up to n - (k-1)
        for (int i1 = 2; i1 <= n - (k - 1); i1++) {
            // Outgoing: the element that was at i1 (now i1 is the start, can't be in the 'extra' pool)
            remove(nums[i1]);
            
            // Incoming: the element at the new edge of the dist-range
            if (i1 + dist < n) {
                add(nums[i1 + dist]);
            }

            // Calculate cost for this specific i1
            long long currentCost = (long long)nums[0] + nums[i1] + currentWindowSum;
            minTotalCost = min(minTotalCost, currentCost);
        }

        return minTotalCost;
    }
};