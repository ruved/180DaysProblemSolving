class Solution {
public:
vector<vector<int>> dp;

    int solve(vector<int>& A, vector<int>& B, int i, bool swappedPrev) {
        if(i == A.size()) return 0;

        if(dp[i][swappedPrev] != -1)
            return dp[i][swappedPrev];

        int prevA = A[i-1];
        int prevB = B[i-1];

        if(swappedPrev)
            swap(prevA, prevB);

        int ans = 1e9;

        // Option 1: Don't swap at i
        if(A[i] > prevA && B[i] > prevB) {
            ans = min(ans, solve(A, B, i+1, false));
        }

        // Option 2: Swap at i
        if(B[i] > prevA && A[i] > prevB) {
            ans = min(ans, 1 + solve(A, B, i+1, true));
        }

        return dp[i][swappedPrev] = ans;
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // int n = nums1.size();
        // dp.assign(n, vector<int>(2, -1));
        // return solve(nums1, nums2, 1, false);
        int n = nums1.size();

        int keep = 0;   // no swap at i
        int swap = 1;   // swap at i

        for(int i = 1; i < n; i++) {

            int newKeep = INT_MAX;
            int newSwap = INT_MAX;

            // Case 1: natural increasing
            if(nums1[i] > nums1[i-1] &&
               nums2[i] > nums2[i-1]) {

                newKeep = keep;
                newSwap = swap + 1;
            }

            // Case 2: cross increasing
            if(nums1[i] > nums2[i-1] &&
               nums2[i] > nums1[i-1]) {

                newKeep = min(newKeep, swap);
                newSwap = min(newSwap, keep + 1);
            }

            keep = newKeep;
            swap = newSwap;
        }

        return min(keep, swap);
    }
};