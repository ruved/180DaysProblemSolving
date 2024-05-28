class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans=0;
        int j=0;
        for(int i=0;i<t.length();++i){
            while(j<=i&&maxCost<abs(s[i]-t[i])){
                    maxCost+=abs(s[j]-t[j]);
                    j++;
            }
            
            if(maxCost>=abs(s[i]-t[i])){
                maxCost-=abs(s[i]-t[i]);
                ans=max(ans,i-j+1);
            }
        }
        return ans;
    }
};