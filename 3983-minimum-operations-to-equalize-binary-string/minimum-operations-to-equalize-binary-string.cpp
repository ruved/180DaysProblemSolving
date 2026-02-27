long long ceil_div(long long a, long long b) {
    if (b <= 0) return LLONG_MAX;
    return (a + b - 1) / b;
}

class Solution {
public:
    int minOperations(const string &s, int k) {
        int n = (int)s.size();
        int z = 0;
        for (char c : s) if (c == '0') ++z;

        if (z == 0) return 0;            // already all ones
        if (k > n) return -1;           // can't pick k distinct indices
        if (k == n) {                   // flip whole string each time
            if (z == n) return 1;       // all zeros -> one flip
            return -1;                  // otherwise alternate forever
        }

        // k < n from here
        long long ans = LLONG_MAX;

        // lower bound from requiring t*k >= z
        long long L1 = ceil_div(z, k);

        // try t even
        if ((z % 2) == 0) {
            // capacity condition for even t: t >= ceil(z/(n-k))
            long long L2 = ceil_div(z, n - k);
            long long L = max(L1, L2);
            if (L < 1) L = 1;
            // smallest even >= L
            long long t = (L % 2 == 0) ? L : L + 1;
            // sanity: ensure t*k >= z (L1 guarantees) and capacity inequality holds by derivation
            if (t > 0) ans = min(ans, t);
        }

        // try t odd
        if ((z % 2) == (k % 2)) {
            // capacity condition for odd t: t >= ceil((n - z)/(n - k))
            long long L2 = ceil_div(n - z, n - k);
            long long L = max(L1, L2);
            if (L < 1) L = 1;
            // smallest odd >= L
            long long t = (L % 2 == 1) ? L : L + 1;
            if (t > 0) ans = min(ans, t);
        }

        return (ans == LLONG_MAX ? -1 : (int)ans);
    }
};