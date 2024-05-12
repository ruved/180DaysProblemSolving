class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int rowlen=grid.size();
        int collen=grid[0].size();
        int k=3;
        vector<vector<int>>ans(rowlen-2,vector<int>(collen-2));
        // map<int,int>mp;
        // //found first submatrix max
        // for(int i=0;i<3;++i)
        //     for(int j=0;j<3;++j)
        //         mp[grid[i][j]]++;
        // auto it=mp.rbegin();
        // ans[0][0]=it->first;

        // map<int,int>rowwisemp=mp;
        // for(int i=3;i<rowlen;++i)
        // {
        //     for(int j=0;j<k;++j)
        //         rowwisemp[grid[i][j]]++;
            
        //     for(int j=0;j<k;++j)
        //     {
        //         rowwisemp[grid[i-k][j]]--;
        //         if(rowwisemp[grid[i-k][j]]==0)
        //         rowwisemp.erase(grid[i-k][j]);
        //     }
        //     auto it=rowwisemp.rbegin();
        //     ans[i-k][0]=it->first;
        // }

        // for(int i=3;i<collen;++i)
        // {
        //     for(int j=0;j<k;++j)
        //         mp[grid[j][i]]++;
        //     for(int j=0;j<k;++j){
        //         mp[grid[j][i-k]]--;
        //     if(mp[grid[j][i-k]]==0)
        //         mp.erase(grid[j][i-k]);}

        // auto it=mp.rbegin();
        // ans[1][i-k+1]=it->first;

        // map<int,int>rowwisemp=mp;
        // for(int l=3;l<rowlen;++i)
        // {
        //     for(int m=0;m<k;++m)
        //         rowwisemp[grid[l][m]]++;
            
        //     for(int l=l-k+1;l<;++l)
        //     {
        //         rowwisemp[grid[i-k][j]]--;
        //         if(rowwisemp[grid[i-k][j]]==0)
        //         rowwisemp.erase(grid[i-k][j]);
        //     }
        //     auto it=rowwisemp.rbegin();
        //     ans[l-k+1][i-k+1]=it->first;
        // }
        // }
        // return ans;
        for(int i=0;i<rowlen-2;++i)
        {
            for(int j=0;j<collen-2;++j)
            {
                int maxi=0;
                for(int l=i;l<i+k;++l)
                    for(int m=j;m<j+k;++m)
                        maxi=max(maxi,grid[l][m]);
                ans[i][j]=maxi;
            }
        }
        return ans;

    }
};