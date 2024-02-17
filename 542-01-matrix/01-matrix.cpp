class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int inf=m+n;
        vector<vector<int>>res(m,vector<int>(n,inf));

        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(mat[i][j]==0) res[i][j]=0;
                else
                {
                    int a=inf,b=inf;
                    if(i-1>=0)
                        a=res[i-1][j];
                    if(j-1>=0)
                        b=res[i][j-1];
                   
                    res[i][j]= 1+min(a,b);
                }
            }
        }
        for(int i=m-1;i>=0;--i)
        {
            for(int j=n-1;j>=0;--j)
            {
                if(mat[i][j]==0) res[i][j]=0;
                else
                {
                    int a=inf,b=inf;
                    if(i+1<m)
                        a=res[i+1][j];
                    if(j+1<n)
                        b=res[i][j+1];
                     int ans=1+min(a,b);
                    res[i][j]=min(res[i][j],ans);
                }
           
            }
        }
        
        return res;
    }
};