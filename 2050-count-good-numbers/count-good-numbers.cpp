class Solution {
public:
     
    long long powerMod(int a, long long b, int mod) {
        if(b == 0)
            return 1;
        long long x = powerMod(a, b/2, mod);
        if(b % 2 == 0)
            return (x * x) % mod;
        else
            return (((a * x) % mod) * x) % mod;
    }
    int countGoodNumbers(long long n) {
   long long int m=1000000007;
    long long unsigned int ans=1;
        long long mid=n/2;
        // cout<<mid<<" ";
        if(mid!=0)
        {
            long long ans1=powerMod(5,mid,m);
            long long ans2=powerMod(4,mid,m);
            ans=(ans*ans1)%m;
            ans=(ans*ans2)%m;
        }
       //odd number 
       if(n&1)
       ans=(ans*5)%m;
        return ans;
    }
};
// 5
// 00000
// 99999
// (0,2,4,6,8)(1,3,5,7)(0,2,4,6,8)
//     5*4*5
// n=5 
// 0,2,4 even(n/2+1)
// 1,3    odd(n/2)
//     n=4
//     0,2 5*5 25*16
//     1,3 4*4
    
    