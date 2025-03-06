class Solution {
public:
    int help(vector<int>& stoneValue,int i,vector<int>&dp){
                
        if(i==stoneValue.size()) return 0;
        if(dp[i]!=INT_MIN) return dp[i];
        int sum=0;
        int temp=INT_MIN;
        for(int j=i;j<=i+2&&j<stoneValue.size();++j){
            sum+=stoneValue[j];
            int temp2=sum-help(stoneValue,j+1,dp);
            temp=max(temp,temp2);
        }
        return dp[i]=temp;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int>dp(n,INT_MIN);
        int ans=help(stoneValue,0,dp);
        if(ans>0) return "Alice";
        else if(ans<0) return "Bob";
        else return "Tie";
    }
};