class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        stack<pair<char,int>>st;
        st.push({colors[0],0});
        int ans=0;
        for(int i=1;i<neededTime.size();++i){
            if(st.top().first==colors[i]){
                if(neededTime[st.top().second]<neededTime[i]){
                    ans+=neededTime[st.top().second];
                    st.pop();
                    st.push({colors[i],i});  
                }else{
                    ans+=neededTime[i];
                }
             
            }else
                    st.push({colors[i],i});
        }
        return ans;
    }
};