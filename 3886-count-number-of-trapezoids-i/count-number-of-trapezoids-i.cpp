class Solution {
public:
int mod=1e9+7;

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,unordered_set<int>>mp;
        for(int i=0;i<points.size();++i)
            mp[points[i][1]].insert(points[i][0]);
        unordered_map<int,int>umap;
        long total=0;
        for(auto it=mp.begin();it!=mp.end();++it){
            long temp=it->second.size();
            temp=(temp*(temp-1))/2;
            umap[it->first]=temp%mod;
            total+=temp;
            total%=mod;
        }
        
        long ans=0;
        for(auto it=umap.begin();it!=umap.end();++it){
            long  up=it->second;
            long bottom=total-up;
            total-=up;
            ans+=(up%mod*bottom%mod)%mod;
        }
        return ans%mod;
    }
};