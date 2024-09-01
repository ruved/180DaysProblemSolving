class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int originalSize=original.size();
        if(originalSize!=m*n) return {};
        vector<vector<int>>res(m,vector<int>(n));
        int i=0;

        for(int row=0;row<m;++row){
            for(int col=0;col<n;++col){
                res[row][col]=original[i++];
            }
        }
        return res;
    }
};