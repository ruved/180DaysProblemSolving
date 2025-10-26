class Solution {
public:
    long long removeZeros(long long n) {
        long long i=1;
        long long res=0;
        while(n){
            long long d=n%10;
            n=n/10;
            if(d==0) continue;
           res=d*i+res;
             i*=10;
        }
        
        return res;

    }
};