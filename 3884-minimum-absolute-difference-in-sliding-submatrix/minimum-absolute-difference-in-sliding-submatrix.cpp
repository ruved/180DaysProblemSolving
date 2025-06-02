class Solution {
public:
    int minDif(map<int,int>&mp){
        int pos=INT_MIN;
        int mn=INT_MAX;
        if(mp.size()>1){
            for(auto it:mp){
                if(pos!=INT_MIN){
                    mn=min(mn,abs(it.first-pos));
                }
                pos=it.first;
            }
            return mn;
        }
        else 
            return 0;
    }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>>ans(m-k+1,vector<int>(n-k+1));
    map<int,int>mp;
        for(int i=0;i<=m-k;++i){
             mp.clear();
            for(int l=i;l<i+k;++l)
            for(int j=0;j<k;++j) mp[grid[l][j]]++;
            ans[i][0]=minDif(mp);
            for(int j=1;j<=n-k;++j){
                int y=i+k-1;
                while(y>=i) {
                    mp[grid[y][j+k-1]]++; mp[grid[y][j-1]]--; 
                             if(mp[grid[y][j-1]]==0) mp.erase(grid[y][j-1]);
                             y--;
                }
                ans[i][j]=minDif(mp);
            }
           
        }
        return ans;
    }
};