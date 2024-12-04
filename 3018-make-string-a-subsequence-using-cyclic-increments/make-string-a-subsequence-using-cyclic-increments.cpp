class Solution {
public:
bool help(string &str1, string &str2,int i,int j){
    if(j<0) return true;
    if(i<0) return false;
    if(str1[i]==str2[j]) return help(str1,str2,i-1,j-1);
    else {
        int a=str1[i]-'a';
        int b=str2[j]-'a';
        if((a+1)%26==b)
        return help(str1,str2,i-1,j-1);
        else
           return help(str1,str2,i-1,j);
    }

}
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.length()-1;
        int m=str2.length()-1;
        return help(str1,str2,n,m);      
    }
};