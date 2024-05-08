class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int,int>>rank(score.size());
        for(int i=0;i<score.size();++i)
            rank[i]={score[i],i};
        
        sort(rank.begin(),rank.end(),greater<pair<int,int>>());
        
        int n=score.size();
        vector<string>res(score.size());
        if(n>=1)
            res[rank[0].second]="Gold Medal";
        if(n>=2)
            res[rank[1].second]="Silver Medal";
        if(n>=3)
            res[rank[2].second]="Bronze Medal";
        for(int i=3;i<score.size();++i)
        {
            res[rank[i].second]=to_string(i+1);
        }
        return res;


    }
};