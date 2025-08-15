class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,int>mp;
        int n=nums2.size()-1;
        stack<int>st;
        for(int i=n;i>=0;--i){
            while(!st.empty()&&st.top()<=nums2[i])
                st.pop();
             mp[nums2[i]]=st.empty()?-1:st.top(); 
             st.push(nums2[i]);
        }
        for(int num:nums1){
            ans.push_back(mp[num]);
        }
        return ans;
    }
};