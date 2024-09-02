class Solution {
public:
   bool is_Interleave(string s1, int i, string s2, int j, string s3, int k,vector<vector<int>>& memo) {
        if (i == s1.length()) {
            return s2.substr(j) == s3.substr(k);
        }
        if (j == s2.length()) {
            return s1.substr(i) == s3.substr(k);
        }
        if (memo[i][j] >= 0) {
            return memo[i][j] == 1 ? true : false;
        }
        bool ans = false;
        if ((s3[k] == s1[i] &&is_Interleave(s1, i + 1, s2, j, s3, k + 1, memo)) ||
            (s3[k] == s2[j] &&is_Interleave(s1, i, s2, j + 1, s3, k + 1, memo))) {
            ans = true;
        }
        memo[i][j] = ans ? 1 : 0;
        return ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        vector<vector<int>> memo(s1.length(), vector<int>(s2.length(), -1));
        return is_Interleave(s1, 0, s2, 0, s3, 0, memo);
    }
};