class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](auto &a, auto &b){
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });
        vector<int> heights;
    for (auto &env : envelopes) heights.push_back(env[1]);

   
    vector<int> lis;
    for (int h : heights) {
        auto it = lower_bound(lis.begin(), lis.end(), h);
        if (it == lis.end()) lis.push_back(h);
        else *it = h; // replace
    }
    return lis.size();
    }
};