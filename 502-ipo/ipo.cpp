class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>vc;
        priority_queue<pair<int,int>>q;
        for(int i=0;i<profits.size();++i)
            vc.push_back({capital[i],profits[i]});

        sort(vc.begin(),vc.end());
        int tw=w;
    int tk=k;
    int i=0,n=vc.size();
        while(tk--){
            while(i<n&&vc[i].first<=tw){
                q.push({vc[i].second,vc[i].first});
                i++;
            }
            if(q.empty()) break;
            tw+=q.top().first;
            q.pop();
        }
        
        return tw;
    }
};