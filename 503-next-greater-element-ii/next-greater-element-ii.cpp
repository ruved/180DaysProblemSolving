class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>nums2(nums.begin(),nums.end());

        for(int i=0;i<nums.size();++i)
            nums2.push_back(nums[i]);
        stack<int>st;
        vector<int>ans(nums.size());
        for(int i=nums2.size()-1;i>=0;--i){
            if(!st.empty()&&st.top()<=nums2[i]){
                while(!st.empty()&&st.top()<=nums2[i])
                    st.pop();
            }
            if(i<nums.size())
            ans[i]=(!st.empty())?st.top():-1;
            st.push(nums2[i]);
        }
        
        return ans;
    }
};