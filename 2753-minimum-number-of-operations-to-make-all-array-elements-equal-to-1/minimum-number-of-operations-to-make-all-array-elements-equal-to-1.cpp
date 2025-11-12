class Solution {
public:
int gcd(int a,int b){
    if(a==0) return b;
    else if(b==0) return a;

    return gcd(b,a%b);
}
    int minOperations(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<nums.size();++i){
            if(nums[i]==1) cnt++;
        }
        if(cnt>0) return nums.size()-cnt;
        int overall = nums[0];
        for (int i = 1; i < n; ++i) overall = gcd(overall, nums[i]);
        if (overall > 1) return -1;

        // find shortest subarray with gcd == 1
        int bestLen = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int g = nums[i];
            if (g == 1) { bestLen = 1; break; }
            for (int j = i + 1; j < n; ++j) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    bestLen = min(bestLen, j - i + 1);
                    break; // for this i, no need to extend j further
                }
            }
        }
        if (bestLen == INT_MAX) return -1; 
        return (bestLen - 1) + (n - 1); 
    }
};