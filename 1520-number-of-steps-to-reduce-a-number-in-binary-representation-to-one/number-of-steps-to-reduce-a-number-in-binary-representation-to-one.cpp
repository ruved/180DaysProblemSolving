class Solution {
public:
    int numSteps(string s) {
        int i=s.length()-1;
        int step=0;
        int carry=0;
        while(i>0)
        {
            if(s[i]=='0') {
                step+=carry?2:1;
            }
            else{
                step+=carry?1:2;
                carry=1;
            }
            i--;
        }
        if(carry) step++;
        return step;
    }
};