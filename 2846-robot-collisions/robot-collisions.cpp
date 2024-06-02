class Solution {
public:
static bool cmp(vector<int>a,vector<int>b){
    return a[3]<b[3];
}
vector<int>help(vector<vector<int>>&robot){
    stack<vector<int>>st;
       for(int i=0;i<robot.size();++i){
        if(robot[i][2]==1){
            vector<int> temp=robot[i];
            bool b=true;
            while(!st.empty()&&st.top()[2]==0&&temp[2]==1&&b){
               if(st.top()[1]<temp[1])
                temp[1]--;
                else if(st.top()[1]>temp[1]){
                    temp=st.top();
                    temp[1]--;
                }
                else b=false;
               st.pop();
            }
            if(b)
            st.push(temp);
        }
        else{
            st.push(robot[i]);
        }
       } 

       vector<vector<int>>ans(st.size());
       int n=st.size()-1;
       while(!st.empty()){
        ans[n--]=st.top();
        st.pop();
       }
       sort(ans.begin(),ans.end(),cmp);
       vector<int>res(ans.size());
       for(int i=0;i<ans.size();++i)
       res[i]=ans[i][1];
       return res;
}
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<vector<int>>robot(positions.size());
        for(int i=0;i<positions.size();++i){
            vector<int>temp;
            temp.push_back(positions[i]);
            temp.push_back(healths[i]);
            if(directions[i]=='L')
            temp.push_back(1);
            else
            temp.push_back(0);
            temp.push_back(i);
            robot[i]=temp;
        }
        sort(robot.begin(),robot.end());
    return help(robot);
    }
};