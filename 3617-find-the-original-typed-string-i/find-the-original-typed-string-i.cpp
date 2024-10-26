class Solution {
public:
    int possibleStringCount(string word) {
      int ans=0;
      int i=0;  
      while(i<word.length()){
        int j=i+1;
        while(j<word.length()&&word[j]==word[i]){
            j++;
        }
        ans+=j-i-1;
        i=j;
      }  
      return ans+1;
    }
};