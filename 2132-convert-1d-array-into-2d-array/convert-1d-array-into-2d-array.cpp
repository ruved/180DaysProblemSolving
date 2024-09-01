class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int list1=original.size();
        
        if(list1!=m*n) return {};
        vector<vector<int>>ans(m,vector<int>(n));
        int i=0;
        int row=0,col=0;
        for(int row=0;row<m;++row){
            for(int col=0;col<n;++col){
                ans[row][col]=original[i++];
            }
        }
        return ans;
    }
};