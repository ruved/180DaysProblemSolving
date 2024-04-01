class Solution {
public:
    int lengthOfLastWord(string s) {
       int i=0;
       int j=s.length()-1;
       while(j>=0&&s[j]==' ')
       j--;
       while(j>=0)
       {
        if(s[j]==' ')
        return i;
        i++;
        j--;
       }
    return i;
    }
};