class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long ,vector<long>,greater<long>>pq;
        for(int i=0;i<nums.size();++i)
            pq.push(nums[i]);
        int ans=0;
        while(pq.size()>1){
            if(pq.top()>=k) break;
            long int x=pq.top();
            pq.pop();
           long int y=pq.top();
            pq.pop();
            long long int res=x+y;
            if(x>y) 
                res+=y;
            else 
                res+=x;
            pq.push(res);
            ans++;
        }
        return ans;
    }
};