class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n=nums.size();
        stack<pair<int,int>>st;
        vector<int>ans(nums.size());

        for(int i=n-1;i>=0;--i){
            if(!st.empty()&&st.top().first<=nums[i]){
                while(!st.empty()&&st.top().first<=nums[i])
                    st.pop();
            }
            ans[i]=(!st.empty())?st.top().second-i:0;
            st.push({nums[i],i});
        }
        
        return ans;
    }
};