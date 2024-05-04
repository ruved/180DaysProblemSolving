class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        int ans=0;
        for(int i=0;i<piles.size();++i)
        {   
             pq.push(piles[i]);
            ans+=piles[i];
        }
        while(k--)
        {
            int t=pq.top();
            pq.pop();
            pq.push(t-t/2);
        }
        int res=0;
        while(!pq.empty())
        {
            res+=pq.top();
            pq.pop();
        }
        return res;
    }
};