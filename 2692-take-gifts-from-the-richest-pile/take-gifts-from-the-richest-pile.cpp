class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>q;
        for(int i=0;i<gifts.size();++i)
            q.push(gifts[i]);
        
        for(int i=1;i<=k;++i){
            int t=q.top();
            int x=sqrt(t);
            q.pop();
            q.push(x);
        }
        long long res=0;
        while(!q.empty()){
            res+=q.top();
            q.pop();
        }
        return res;
    }
};