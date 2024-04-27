class Solution {
public:
int findSteps(int p1, int p2, string &ring, string &key,vector<vector<int>>& pos,vector<vector<int>>&dp) {
        if(p2==key.size()) return 0;
        if(dp[p1][p2]!=-1) return dp[p1][p2];
        int r = ring.size(), ms=INT_MAX;

        for(int nxt:pos[key[p2]-'a']) {
            int dist = abs(p1-nxt);
            ms = min(ms,min(dist, r-dist)+findSteps(nxt,p2+1,ring,key,pos,dp));    
        }
        return dp[p1][p2]=ms+1;
    }
    int findRotateSteps(string ring, string key) {
        vector<vector<int>>mpring(26);
        for(int i=0;i<ring.size();++i)
            mpring[ring[i]-'a'].push_back(i);

        int ringlen=ring.length();
        vector<vector<int>>dp(ring.size(),vector<int>(key.size(),-1));
        return findSteps(0,0,ring,key,mpring,dp);
    }
};