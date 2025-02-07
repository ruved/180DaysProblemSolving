class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int>ans;
        unordered_map<int,int>mp;
        unordered_map<int,int>color;
        for(int i=0;i<queries.size();++i)
        {
            if(mp.find(queries[i][0])!=mp.end()){
                color[mp[queries[i][0]]]--;
                if( color[mp[queries[i][0]]]==0) color.erase(mp[queries[i][0]]);
            }
            mp[queries[i][0]]=queries[i][1];
            color[mp[queries[i][0]]]++;
            ans.push_back(color.size());
        }
        return ans;
    }
};