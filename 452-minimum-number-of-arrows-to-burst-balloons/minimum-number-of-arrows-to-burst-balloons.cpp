class Solution {
public:
static bool cmp(vector<int>a,vector<int>b)
{
    return a[1]<b[1];
}
    int findMinArrowShots(vector<vector<int>>& points) {
       sort(points.begin(),points.end(),cmp);
       int arrowPos = points[0][1];
        int arrowCnt = 1;
        for (int i = 1; i < points.size(); i++) {
            if (arrowPos >= points[i][0]) {
                continue;
            }
            arrowCnt++;
            arrowPos = points[i][1];
        }
        return arrowCnt;
    }
};