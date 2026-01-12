class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        for(int i=1;i<points.size();++i){
            int mn=min(abs(points[i][0]-points[i-1][0]),abs(points[i][1]-points[i-1][1]));
            int x=abs(points[i][0]-points[i-1][0])-mn;
            int y=abs(points[i][1]-points[i-1][1])-mn;
            // cout<<i<<" "<<mn<<" "<<x<<" "<<y<<":";
            ans+=mn+x+y;
        }
        return ans;
    }
};