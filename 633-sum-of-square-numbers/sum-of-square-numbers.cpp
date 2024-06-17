class Solution {
public:
    bool judgeSquareSum(int c) {
       long long j=sqrt(c);
       long long  i=0;
       while(i<=j){
        long  k=i*i+j*j;
        if(k==c) return true;
        else if(k>c) j--;
        else i++;
       }
       return false;
    }
};