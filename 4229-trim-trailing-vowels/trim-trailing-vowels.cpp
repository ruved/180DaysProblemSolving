class Solution {
public:
    string trimTrailingVowels(string s) {
        int n=s.length()-1;
        while(n>=0){
            if((s[n]=='a')||(s[n]=='i')||(s[n]=='e')||(s[n]=='o')||(s[n]=='u'))
                n--;
            else 
                break;
        }
        string ans="";
        while(n>=0){
            ans=s[n]+ans;
            n--;
        }
        return ans;
    }
};