class Solution {
public:
    int climbStairs(int n) {
        int a,b,c;
        if(n==1) return n;
        a=1;
        b=1;
        for(int i=2;i<=n;++i){
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};