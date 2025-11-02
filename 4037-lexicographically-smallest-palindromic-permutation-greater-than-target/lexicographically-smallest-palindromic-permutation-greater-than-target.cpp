class Solution {
public:
    string lexPalindromicPermutation(const string& s, const string& target) {
        int n = (int)s.size();
        if ((int)target.size() != n)
            return "";

        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;

        int oddCount = 0, centerIdx = -1;
        for (int i = 0; i < 26; ++i)
            if (freq[i] % 2) {
                oddCount++;
                centerIdx = i;
            }

        if (n % 2 == 0) {
            if (oddCount != 0)
                return "";
        } else {
            if (oddCount != 1)
                return "";
        }

        vector<int> half(26, 0);
        for (int i = 0; i < 26; ++i) {
            int useForCenter = (i == centerIdx && (n % 2 == 1)) ? 1 : 0;
            half[i] = (freq[i] - useForCenter) / 2;
        }

        int m = n / 2;
        string center =
            (n % 2 == 1) ? string(1, char('a' + centerIdx)) : string();

        auto build_pal = [&](const string& halfStr) -> string {
            string rev = halfStr;
            reverse(rev.begin(), rev.end());
            return halfStr + center + rev;
        };

        // build minimal half (ascending)
        string minimal_half;
        minimal_half.reserve(m);
        for (int i = 0; i < 26; ++i)
            minimal_half.append(half[i], char('a' + i));

        string minimal_pal = build_pal(minimal_half);
        if (minimal_pal > target)
            return minimal_pal;

        string prefix;
        prefix.reserve(m);
        vector<int> cur = half;

        for (int pos = 0; pos < m; ++pos) {
            bool placed = false;
            for (int c = 0; c < 26; ++c) {
                if (cur[c] <= 0)
                    continue;
                // try char c
                cur[c]--;
                // Build maximal suffix (descending) using remaining counts
                string maximal_suffix;
                maximal_suffix.reserve(m - pos - 1);
                for (int k = 25; k >= 0; --k) {
                    if (cur[k] > 0)
                        maximal_suffix.append(cur[k], char('a' + k));
                }
                // candidate half with maximal completion
                string cand_half_max = prefix;
                cand_half_max.push_back(char('a' + c));
                cand_half_max += maximal_suffix;
                string cand_pal_max = build_pal(cand_half_max);

                if (cand_pal_max > target) {

                    prefix.push_back(char('a' + c));
                    placed = true;
                    break; // cur already decremented (we keep it)
                } else {
                    // no completion with this chosen char will beat target
                    cur[c]++;
                }
            }
            if (!placed)
                return "";
        }

        string final_pal = build_pal(prefix);
        if (final_pal > target)
            return final_pal;

        return "";
    }
};