class Solution {
public:
    bool chcekpal(string &s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int palindromeLength=0;
        int strt=0,end=0;
        for(int i=0;i<s.length();++i)
        {
             for(int j=i+1;j<s.length();++j)
             {
                 if(chcekpal(s,i,j)&&(palindromeLength<(j-i+1)))
                 {
                     palindromeLength=j-i+1;
                     strt=i;
                     end=j;
                 }
             }
        }
       
        return s.substr(strt,end-strt+1);
        
    }
};