class Solution {
public:
int help(vector<vector<int>>& books, int &shelfWidth,int i,vector<int>&dp){
    if(i<0) return 0;
    if(dp[i]!=-1) return dp[i];

    int ans=0;
    int k=0;
    int j=i;
    int res=INT_MAX;
    while(j>=0 &&shelfWidth>=k+books[j][0]){
            k+=books[j][0];
            ans=max(ans,books[j][1]);
            res=min(res,ans+help(books,shelfWidth,j-1,dp));
            --j;
    }
    return dp[i]=res;
}
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        vector<int>dp(n,-1);
       return help(books,shelfWidth,books.size()-1,dp);
    }
};