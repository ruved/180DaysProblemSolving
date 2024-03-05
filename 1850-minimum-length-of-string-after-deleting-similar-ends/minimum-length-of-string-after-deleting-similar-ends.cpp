class Solution {
public:
    int minimumLength(string s) {
        int i=0,j=s.length()-1;
        int count=0;
        while(i<j)
        {
            char prev1=s[i];
            char prev2=s[j];
            if(prev1==prev2)
            {
                while(i<=j&&prev1==s[i])
                {
                    i++;
                    count++;
                }
                while(j>=i&&prev2==s[j])
                {
                    j--;
                    count++;
                }
            }
            
            else
                break;
        }
        return s.length()-count;
    }
};