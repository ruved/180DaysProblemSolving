class Solution {
public:
    #define ll long long

    ll mini = 1e8; 
    ll sum = 0;
    int n;
    int mod = 1e9+7;

    ll solve(vector<int>& nums, int c1, int c2, ll maxi) {
       
       ll mxdiff = maxi-mini;
       
       ll total = maxi*n - sum;

       if(2*c1 <= c2) return total*c1;

       ll last = total - mxdiff;

       if(mxdiff > total/2) return (mxdiff-last)*c1 + last*c2;

       if(total%2 == 0) return (total/2)*c2;
       else return (total/2)*c2 + c1;

    }

    int minCostToEqualizeArray(vector<int>& nums, int c1, int c2) {

        n = nums.size();

        ll maxi = 0;

        for(int i=0; i<n; i++) {
            mini = min(mini, 1LL*nums[i]);
        }

        for(int i=0; i<n; i++) {
            maxi = max(maxi, 1LL*nums[i]);
            sum += nums[i];
        }
        
        ll ans = 1e18;

        for(int i=maxi; i<=2*maxi; i++) {
            ll tmp = solve(nums, c1, c2, i);
            ans = min(ans, tmp);
        }
        
        return ans%mod;
    } 
};