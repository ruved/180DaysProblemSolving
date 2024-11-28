class Solution {
public:
bool isSafe(int x,int y,int n,int m){
    
    if(x<0 or y<0 or x>=n or y>=m) return false;
    return true;
}
    int minimumObstacles(vector<vector<int>>& grid) {
            int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
    dist[0][0]=0;
    priority_queue <tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>> > pq; 
    pq.push({0,0,0}); // weight , x cor, y cor
    
    while(!pq.empty()){
        
        int wt,x,y;
        tie(wt,x,y) = pq.top();
        pq.pop();
        if(isSafe(x-1,y,n,m) and dist[x-1][y]>wt+grid[x][y]){
            
            dist[x-1][y]=wt+grid[x][y];
            pq.push(make_tuple(dist[x-1][y],x-1,y));
        }
        
        if(isSafe(x+1,y,n,m) and dist[x+1][y]>wt+grid[x][y]){
            
            dist[x+1][y]=wt+grid[x][y];
            pq.push(make_tuple(dist[x+1][y],x+1,y));
        }
        
        if(isSafe(x,y-1,n,m) and dist[x][y-1]>wt+grid[x][y]){
            
            dist[x][y-1]=wt+grid[x][y];
            pq.push(make_tuple(dist[x][y-1],x,y-1));
        }
        
        if(isSafe(x,y+1,n,m) and dist[x][y+1]>wt+grid[x][y]){
            
            dist[x][y+1]=wt+grid[x][y];
            pq.push(make_tuple(dist[x][y+1],x,y+1));
        }
        
    }
    return dist[n-1][m-1];
}
};