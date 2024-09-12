class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        int lastone=1;
        int lasttwo=2;
        int res=2;
        for(int i=3;i<=n;++i){
            res=lasttwo+lastone;
            lastone=lasttwo;
            lasttwo=res;
        }   
        return res;
    }
};