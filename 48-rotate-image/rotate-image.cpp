class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //transpose the matrix
        //reverse the every row
        int row=matrix.size();
        int col=matrix[0].size();
        for(int i=0;i<row;++i){
            for(int j=i;j<col;++j){
                int t=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=t;
            }
        }

        for(int i=0;i<row;++i)
        {
            int j=0,k=col-1;
            while(j<k){
                int t=matrix[i][j];
                matrix[i][j++]=matrix[i][k];
                matrix[i][k--]=t;
            }
        }
        
    }
};