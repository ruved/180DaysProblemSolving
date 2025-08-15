class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
         vector<int>ans(nums.size());
   
        int n=nums.size();
        stack<int>st;
        for(int i=2*n-1;i>=0;--i){
            int cur=nums[i%n];
            while(!st.empty()&&st.top()<=cur)
                st.pop();
             ans[i%n]=st.empty()?-1:st.top(); 
             st.push(cur);
        }       
     
        return ans;
    }
};