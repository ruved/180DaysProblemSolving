class Solution {
public:
    int help(string s,int i,vector<int>&dp)
    {
        if(i==s.length())
            return 1;
        if(dp[i]!=-1) return dp[i];
        
        int ans=0;
        
        if(s[i]=='0') return 0;
    
        if(i<s.length()-1)
        {
            if((s[i]=='1'||s[i]=='2')&&s[i+1]=='0')
                ans+=help(s,i+2,dp);
            else
            {
                if((s[i]=='2'&&s[i+1]-'0'<=6)||s[i]=='1')
                    ans+=help(s,i+2,dp);
            }  
        }
        ans+=help(s,i+1,dp);
        dp[i]=ans;
         return ans;   
    }
    int numDecodings(string s) {
        vector<int>dp(s.length()+1,-1);
        return help(s,0,dp);
    }
};
           
//11101
//s[i]=0