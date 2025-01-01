class Solution {
public:
    int maxScore(string s) {
        int n=s.length();
        int ones=0;
        for(int i=0;i<n;++i)
            if(s[i]=='1') ones++;
        int zero=0;
        if(s[0]=='0')
            zero++;
        else ones--;
        int ans=0;
        for(int i=1;i<n-1;++i){
            ans=max(ans,zero+ones);
            if(s[i]=='1')
                ones--;
            else 
                zero++;
            
        }
       ans=max(ans,zero+ones);
        return ans;
    }
};