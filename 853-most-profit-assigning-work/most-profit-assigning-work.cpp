class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>vc;
        for(int i=0;i<difficulty.size();++i)
            vc.push_back({profit[i],difficulty[i],});
        sort(vc.begin(),vc.end());
        // sort(worker.begin(),worker.end());
        int res=0;
        
        for(int j=0;j<worker.size();++j){
            int k=vc.size()-1;
            int temp=0;
            while(k>=0&&worker[j]<vc[k].second){
                k--;
            }
            if(k!=-1)
            res+=vc[k].first;
        }
        return res;
    }
};