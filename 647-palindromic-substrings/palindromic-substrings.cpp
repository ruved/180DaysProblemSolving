class Solution {
public:
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.length();++i){
            for(int j=i;j<s.length();++j)
            {
                string str1=s.substr(i,j-i+1);
                string temp=str1;
              
                reverse(str1.begin(),str1.end());
                if(str1==temp)
                    ans++;
            }
        }
        return ans;
    }
};