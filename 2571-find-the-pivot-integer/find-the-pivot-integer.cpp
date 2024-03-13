class Solution {
public:
    int pivotInteger(int n) {
        int x=n*(n+1)/2;
        int r=sqrt(x);
         if(r*r==x)
             return r;
        else
            return -1;
    }
};