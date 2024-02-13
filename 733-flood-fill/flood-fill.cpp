class Solution {
public:
    void help(vector<vector<int>>& image, int sr, int sc, int &color, vector<vector<bool>> &vis)
    {
        
        vis[sr][sc]=true;
        // image[sr][sc]=color;
        if(sr+1<image.size()&&!vis[sr+1][sc]&&image[sr][sc]==image[sr+1][sc])
            help(image,sr+1,sc,color,vis);
        if(sc+1<image[0].size()&&!vis[sr][sc+1]&&image[sr][sc]==image[sr][sc+1])
            help(image,sr,sc+1,color,vis);
        if(sr-1>=0&&!vis[sr-1][sc]&&image[sr][sc]==image[sr-1][sc])
            help(image,sr-1,sc,color,vis);
        if(sc-1>=0&&!vis[sr][sc-1]&&image[sr][sc]==image[sr][sc-1])
            help(image,sr,sc-1,color,vis);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        help(image,sr,sc,color,vis);
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                if(vis[i][j])
                    image[i][j]=color;
        return image;
    }
};