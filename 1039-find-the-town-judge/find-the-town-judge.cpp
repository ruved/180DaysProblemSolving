class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        set<int>tr;
        map<int,set<int>>mp;
        for(int i=0;i<trust.size();++i)
        {
           tr.insert(trust[i][0]);
            mp[trust[i][0]].insert(trust[i][1]);
        }
    int c=0,ans=-1;
        for(int i=1;i<=n;++i)
            if(tr.find(i)==tr.end())
            {
                ans=i;
                c++;
            }    
    if(c!=1)
        return -1;
// cout<<ans<<" :";
        for(int i=1;i<=n;++i)
            if((i!=ans)&&mp[i].find(ans)==mp[i].end())
                return -1;
            
        return ans;
    }
};