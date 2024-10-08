class disjointset{
    public:
    vector<int>par;
    disjointset(int n){
        par.resize(n+1);
        for(int i=0; i<=n; i++){
            par[i]=i;
        }
    }
    int findp(int u){
        if(u==par[u]){return u;}
        return par[u]=findp(par[u]);
    }
    void un(int u, int v){
        if(findp(u)==findp(v)){return;}
        par[findp(u)]=par[findp(v)];
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int, pair<int, int>>>v;
        for(int i=0; i<points.size(); i++){
            for(int j=i+1; j<points.size(); j++){
                v.push_back({abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]), {i, j}});
            }
        }
        disjointset d(points.size());
        sort(v.begin(), v.end());
        int ans=0;
        for(auto it: v){
            if(d.findp(it.second.first)!=d.findp(it.second.second)){
                ans+=it.first;
                d.un(it.second.first, it.second.second);
            }
        }
        return ans;
    }
};