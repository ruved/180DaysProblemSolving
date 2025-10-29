class Solution {
public:
    int smallestNumber(int n) {
        int x=0;
        while(n){
            x=x<<1;
            x++;
            n=n>>1;
        }
        return x;
    }
};