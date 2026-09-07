class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        stack<vector<int>>st;
        st.push({intervals[0][0],intervals[0][1]});
        for(int i=1;i<intervals.size();++i){
            vector<int>last=st.top();
            if(intervals[i][0]<=last[1]){
                st.pop();
                st.push({min(last[0],intervals[i][0]),max(last[1],intervals[i][1])});
            }else{
                st.push({intervals[i][0],intervals[i][1]});
            }
        }
        vector<vector<int>>res;
        while(!st.empty()){
            res.push_back({st.top()[0],st.top()[1]});
            st.pop();
        }
        return res;
    }
};