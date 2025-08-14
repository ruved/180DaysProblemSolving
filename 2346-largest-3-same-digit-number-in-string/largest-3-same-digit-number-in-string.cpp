class Solution {
public:
    string largestGoodInteger(string num) {
        int  ans=-1;
        for(int i=0;i<num.length()-2;++i){
            if((num[i]==num[i+1])&&(num[i+1]==num[i+2]))
               ans=max(ans,num[i]-'0');
        }
        if(ans==-1) return "";
        string res="";
        res=('0'+ans);
        res+=('0'+ans);
        res+=('0'+ans);
        return res;
    }
};