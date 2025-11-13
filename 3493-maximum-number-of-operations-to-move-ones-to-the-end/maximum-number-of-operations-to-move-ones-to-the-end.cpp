class Solution {
public:
    int maxOperations(string s) {
        int n=s.length();
        int totalone=0;
        
        int ans=0;
        int i=0;
        while(i<n){
            if(s[i]=='0'){
                 while(s[i]=='0') i++;
                ans+=totalone;
            }
            else{ 
             totalone++;
             i++;
            }
            
        }
        
        
        return ans;
    }
};