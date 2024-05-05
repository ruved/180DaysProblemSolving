class Solution {
public:
    bool isValid(string word) {
        if(word.length()<3) return false;
        int vcount=0,ccount=0;
        
        for(int i=0;i<word.length();++i)
        {
            if((word[i]=='@'||word[i]=='#'||word[i]=='$'))
             {
               return false;  
             }
             else if(word[i]-'0'>=0&&word[i]-'0'<=9)
             {
                continue;
             }
             else{
                   char c=tolower(word[i]);
                   if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
                       vcount++;
                   else
                       ccount++;
               }
              
        }
         if(vcount&&ccount)
               return true;
        return false;  
    }
};