class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> seen;
        if(s.length()<=k) return false;
        // Extract all substrings of length k
        for (int i = 0; i <= s.length() - k; i++) {
            string sub = s.substr(i, k);
            seen.insert(sub);
        }

        // Total number of unique binary strings of length k
        int total = 1 << k; // 2^k

        return seen.size() == total;
    }
};