class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count1=0;
        for(int i=0;i<s.length();++i)
            if(s[i]=='1')
            count1++;
        string ans="";
        
        for(int i=2;i<=count1;++i)
            ans+="1";
        for(int i=1;i<=s.length()-count1;++i)
            ans+="0";
        if(count1>=1)
            ans+="1";
        return ans;
    }
};