class Solution {
public:
    long long minimumTime(vector<int>& d, vector<int>& r) {
         using ll = long long;
    // assume d.size() == 2 and r.size() == 2
    ll d1 = d[0], d2 = d[1];
    ll r1 = r[0], r2 = r[1];

    auto gcd64 = [&](ll a, ll b) {
        while (b) {
            ll t = a % b;
            a = b;
            b = t;
        }
        return a;
    };

    auto feasible = [&](ll t) -> bool {
        if (t < 0) return false;

        // available hours for each drone
        ll A1 = t - t / r1;
        ll A2 = t - t / r2;
        if (A1 < d1 || A2 < d2) return false;

        // compute lcm safely with 128-bit
        ll g = gcd64(r1, r2);
        __int128 lc = (__int128)(r1 / g) * (__int128)r2;

        // hours where both are unavailable = floor(t / lcm)
        ll both_unavailable = 0;
        if (lc <= (__int128)t) both_unavailable = (ll)((__int128)t / lc);

        // union available hours = t - both_unavailable
        ll U = t - both_unavailable;
        return U >= d1 + d2;
    };

    // binary search for minimum t
    ll lo = 0, hi = 1;
    // expand hi until feasible (with a safety cap)
    while (!feasible(hi)) {
        hi <<= 1;
        if (hi <= 0 || hi > (ll)9e18) { hi = (ll)9e18; break; }
    }

    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (feasible(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
    }
};