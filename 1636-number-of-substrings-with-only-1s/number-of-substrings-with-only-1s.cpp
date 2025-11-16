class Solution {
public:
    int numSub(string s) {
    
        int mod=1e9+7;
        long sum=0;
        int start=0;
        int end=0;
        long tempsum=0;
        while(end<s.length()){
            if(s[end]=='1'){
               start++;
               tempsum+=start;
               tempsum=tempsum%mod;
            }else{
                
                sum+=tempsum;
                sum=sum%mod;
                start=0;
                tempsum=0;
            }
            end++;
            
        }
        return (sum%mod+tempsum%mod)%mod;
    }
};