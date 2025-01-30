class Solution {
public:
int help(vector<vector<int>>& books,int i, int &shelfWidth,vector<int>&dp){
    
    if(i<0) return 0;
    if(dp[i]!=-1) return dp[i];

    int rmw=shelfWidth;
    int height=0;
    int ans=INT_MAX;
    int j=i;
    while(i>=0 && (rmw >= books[i][0])){
        height=max(height,books[i][1]);
        int temp=help(books,i-1,shelfWidth,dp);
        ans=min(ans,height+temp);
        rmw-=books[i][0];
        i--;
    }
    return dp[j]=ans;
}
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        vector<int>dp(n,-1);
        return help(books,n-1,shelfWidth,dp);
    }
};


