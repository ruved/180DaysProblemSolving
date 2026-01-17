class Solution {
public:
    long long FindPoints(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
    {
        int x5 = max(x1, x3);
        int y5 = max(y1, y3);
        int x6 = min(x2, x4);
        int y6 = min(y2, y4);

        if (x5 > x6 || y5 > y6)        
            return 0;
    long long a=min(abs(x5-x6),abs(y5-y6));
        return a*a;
    }
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long count=0;
        for(int i=0;i<bottomLeft.size();++i)
        {
            for(int j=i+1;j<topRight.size();++j)
            {
                
        long long area=FindPoints(bottomLeft[i][0],bottomLeft[i][1],topRight[i][0],topRight[i][1],bottomLeft[j][0],bottomLeft[j][1],topRight[j][0],topRight[j][1]);

                    if(count<area)
                        count=area;
            }
        }
        return count;
    }
};