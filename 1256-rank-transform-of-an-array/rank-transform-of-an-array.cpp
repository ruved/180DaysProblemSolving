class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int,int>>p;
        for(int i=0 ;i<arr.size();++i) p.push_back({arr[i],i});
        sort(p.begin(),p.end());
        vector<int>res(arr.size());
        int rank=1;
        for(int i=0;i<arr.size();++i){
            if(i==0||p[i-1].first==p[i].first)
                res[p[i].second]=rank;
            else 
                res[p[i].second]=++rank;
        }
        return res;
    }
};