class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>res(n,vector<int>(n,0));
        for(int q=0;q<queries.size();++q){
            for(int i=queries[q][0];i<=queries[q][2];++i)
                for(int j=queries[q][1];j<=queries[q][3];++j)
                    res[i][j]++;
            // cout<<queries[q][0]<<" "<<queries[q][1]<<" "<<queries[q][2]<<" "<<queries[q][3];
        }
        return res;
    }
};