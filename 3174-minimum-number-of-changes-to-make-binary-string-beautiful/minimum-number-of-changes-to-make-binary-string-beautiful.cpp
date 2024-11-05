class Solution {
public:
    int minChanges(string s) {
        int ans=0;
        int prev=-1;
        int count=0;
        for(int i=0;i<s.length();++i){
            count++;
            if(prev==-1){
                prev=s[i]-'0';
            }

            int t=s[i]-'0';
            if(prev!=t){
                if(count%2==0){
                    ans++;
                    prev=-1;
                }else
                prev=t;
            }
            
        }
        return ans;
    }
};
// 11100111 8
//1111 00 11