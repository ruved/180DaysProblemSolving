class Solution {
public:
    int candy(vector<int>& ratings) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minq;
        for(int i=0;i<ratings.size();++i){
            minq.push({ratings[i],i});
        }
        int n=ratings.size();
        int ans=0;
        vector<int>res(ratings.size(),0);
        while(!minq.empty()){
            pair<int,int>p=minq.top();
            minq.pop();
            int left=p.second-1>=0?ratings[p.second-1]:0;
            int right=p.second+1<n?ratings[p.second+1]:0;

            if(p.first>left&&p.first>right){
                int l=p.second-1>=0?res[p.second-1]:0;
                int r=p.second+1<n?res[p.second+1]:0;
                res[p.second]=max(l,r)+1;
            }else if(p.first>left){
                 int l=p.second-1>=0?res[p.second-1]:0;
                int r=p.second+1<n?res[p.second+1]:0;
                res[p.second]=l+1;
            }else if(p.first>right){
                int l=p.second-1>=0?res[p.second-1]:0;
                int r=p.second+1<n?res[p.second+1]:0;
                res[p.second]=r+1;
            }
            else
                res[p.second]=1;

            cout<<res[p.second]<<" ";
            ans+=res[p.second];
        }
        return ans;
    }
};