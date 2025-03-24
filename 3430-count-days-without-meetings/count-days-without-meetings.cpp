class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
       sort(meetings.begin(),meetings.end());
       int ans=meetings[0][0]-1;
       int last=meetings[0][1];
       for(int i=1;i<meetings.size();++i){
        int dif=meetings[i][0]-last-1;
        ans+=dif<=0?0:dif;
        last=max(meetings[i][1],last);
       } 
       ans+=max(days-last,0);
       return ans;
    }
};