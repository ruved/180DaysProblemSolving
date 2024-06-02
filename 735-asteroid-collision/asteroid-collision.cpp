class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       stack<int>st;
       for(int i=0;i<asteroids.size();++i){
        if(asteroids[i]<0){
            int temp=asteroids[i];
            while(!st.empty()&&st.top()>0&&temp<0){
               if(st.top()>abs(temp))
                temp=st.top();
                else if(st.top()==abs(temp)) temp=0;
               st.pop();
            }
            if(temp!=0)
            st.push(temp);
        }
        else{
            st.push(asteroids[i]);
        }
       } 

       vector<int>ans(st.size());
       int n=st.size()-1;
       while(!st.empty()){
        ans[n--]=st.top();
        st.pop();
       }
       return ans;
    }
};