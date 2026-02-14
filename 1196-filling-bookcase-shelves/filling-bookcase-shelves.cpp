class Solution {
public:
int help(vector<vector<int>>& books, int &shelfWidth,int i,vector<int>&dp){
    if(i<0) return 0;
    if(dp[i]!=-1) return dp[i];
    int width=0;
    int height=0;
    int ans=INT_MAX;
    for(int j=i;j>=0&&width+books[j][0]<=shelfWidth;--j){
        height=max(height,books[j][1]);
        width+=books[j][0];
        ans=min(ans,height+help(books,shelfWidth,j-1,dp));
    }
    return dp[i]=ans;
}
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        // vector<int>dp(n,-1);
        // return help(books,shelfWidth,n-1,dp);
        vector<int>dp(n+1,1e6);
    dp[0]=0;
    for(int i=1;i<=n;++i){
        int width=0, height=0,ans=INT_MAX;
        
        for(int j=i;j>=1&&width+books[j-1][0]<=shelfWidth;--j){
            height=max(height,books[j-1][1]);
            width+=books[j-1][0];
            dp[i]=min(dp[i],height+dp[j-1]);
        }
    }
    return dp[n];
    
    }
};