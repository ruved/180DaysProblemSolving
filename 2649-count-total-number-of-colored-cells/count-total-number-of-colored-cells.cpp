class Solution {
public:
    long long coloredCells(int n) {
        long long ans=0;
        ans=(2*n-2);
        ans=ans*(n-1);
        ans+=(2*n-1);
        return ans;
    }
};