class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        vector<int>ans(nums.size());

        for(int i=2*n-1;i>=0;--i){
            if(!st.empty()&&st.top()<=nums[i%n]){
                while(!st.empty()&&st.top()<=nums[i%n])
                    st.pop();
            }
            ans[i%n]=(!st.empty())?st.top():-1;
            st.push(nums[i%n]);
        }
        
        return ans;
    }
};