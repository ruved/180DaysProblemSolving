class Solution {
public:
    bool isPowerOfTwo(int n) {
        int setbit=0;
        bool b=false;
        if(n<0)
            return false;
        int a=n;
        while(a)
        {
            if(a&1==1)
            {
                setbit++;
                
            }
            a=a>>1;
            
        }
        if(setbit==1)
            return true;
        return false;
    }
};