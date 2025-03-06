class Solution {
public:
    int help(vector<int>& stoneValue,int i,bool flag,vector<vector<int>>&dp){
                
        if(i==stoneValue.size()) return 0;
        if(dp[i][flag]!=INT_MIN) return dp[i][flag];
        int sum=0;
        int temp;
        if(flag)
            temp=INT_MIN;
        else
            temp=INT_MAX;
        for(int j=i;j<=i+2&&j<stoneValue.size();++j){
            sum+=stoneValue[j];
            int temp2=help(stoneValue,j+1,!flag,dp);
            if(flag){
                temp=max(temp,sum+temp2);
            }
            else{
                temp=min(temp,(sum*-1)+temp2);
            }
        }
        return dp[i][flag]=temp;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<vector<int>>dp(n,vector<int>(2,INT_MIN));
        int ans=help(stoneValue,0,true,dp);
        if(ans>0) return "Alice";
        else if(ans<0) return "Bob";
        else return "Tie";
    }
};