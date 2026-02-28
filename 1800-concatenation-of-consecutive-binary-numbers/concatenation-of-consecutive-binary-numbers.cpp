class Solution {
public:


    int concatenatedBinary(int n) {
         const int mod = 1e9 + 7;
        long long res = 0;
        int bitLen = 0;

        for (int i = 1; i <= n; i++) {

            // Check if i is power of 2
            if ((i & (i - 1)) == 0)
                bitLen++;

            res = ((res << bitLen) % mod + i) % mod;
        }

        return res;
    }
};