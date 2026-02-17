class Solution {
public:

    int findSubstringInWraproundString(string s) {
        if (s.empty()) return 0;

        vector<int> maxLen(26, 0);   // max length ending at each character
        int n = s.size();
        int len = 0;                 // current valid chain length
        int ans = 0;

        for (int i = 0; i < n; ++i) {

            if (i > 0 && (s[i] - s[i-1] + 26) % 26 == 1) {
                len++;               // continues wrap sequence
            } else {
                len = 1;             // reset sequence
            }

            int idx = s[i] - 'a';

            // only count new substrings
            if (len > maxLen[idx]) {
                ans += len - maxLen[idx];
                maxLen[idx] = len;
            }
        }

        return ans;
    }
};