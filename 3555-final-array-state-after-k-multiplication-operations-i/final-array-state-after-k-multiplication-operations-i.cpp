class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<nums.size();++i){
            pq.push({nums[i],i});
        }
        for(int i=1;i<=k;++i){
            pair<int,int>topEle=pq.top();
            pq.pop();
            topEle.first=topEle.first*multiplier;
            pq.push(topEle);
        }
        vector<int>ans(nums.size());
        while(!pq.empty()){
            ans[pq.top().second]=pq.top().first;
            pq.pop();
        }
        return ans;
    }
};