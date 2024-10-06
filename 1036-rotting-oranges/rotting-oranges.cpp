class Solution {
public:
bool check(int i,int j,int n,int m){
    if(i<0||j<0||i>=n||j>=m) return false;
    return true;
}
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                if(grid[i][j]==2) q.push({i,j});
        int ans=0;
        while(!q.empty()){
            int s=q.size();
            for(int k=0;k<s;++k){
                int i= q.front().first;
                int j=q.front().second;
                q.pop();
                if(check(i+1,j,n,m)&&grid[i+1][j]==1) {
                    grid[i+1][j]=2;q.push({i+1,j});}
                if(check(i-1,j,n,m)&&grid[i-1][j]==1) {
                    grid[i-1][j]=2;q.push({i-1,j});}
                if(check(i,j+1,n,m)&&grid[i][j+1]==1) {
                    grid[i][j+1]=2;q.push({i,j+1});}
                if(check(i,j-1,n,m)&&grid[i][j-1]==1) {
                    grid[i][j-1]=2;q.push({i,j-1});}
            }
            ans++;
        }
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                if(grid[i][j]==1) return -1;
        return ans==0?ans:ans-1;
    }
};