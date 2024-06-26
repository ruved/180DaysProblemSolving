class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int row=triangle.size();
       vector<int>cur(row,0);
       vector<int>next(row,0);
        for(int i=0;i<row;++i)
            cur[i]=triangle[row-1][i];

        for(int r=row-2;r>=0;--r){
            for(int col=0;col<=r;++col)
                next[col]=triangle[r][col]+min(cur[col],cur[col+1]);
                cur=next;
        }  
        
        return cur[0];
    }
};