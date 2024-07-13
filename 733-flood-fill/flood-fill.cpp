class Solution {
public:
void help(vector<vector<int>>& image, int sr, int sc, int &color,vector<vector<bool>>&vis){

    if(sr<0||sr>=image.size()||sc<0||sc>=image[0].size()) return ;
    if(vis[sr][sc]) return;

    int c=image[sr][sc];
    vis[sr][sc]=true;
    if((sr-1)>=0&&image[sr-1][sc]==c)
        help(image,sr-1,sc,color,vis);
    
    if((sc-1)>=0&&image[sr][sc-1]==c)
        help(image,sr,sc-1,color,vis);
    
    if((sr+1)<image.size()&&image[sr+1][sc]==c)
        help(image,sr+1,sc,color,vis);

    if((sc+1)<image[0].size()&&image[sr][sc+1]==c)
        help(image,sr,sc+1,color,vis);

    image[sr][sc]=color;
    
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

    vector<vector<bool>>vis(image.size(),vector<bool>(image[0].size(),false));
        help(image,sr,sc,color,vis);
        return image;
    }
};