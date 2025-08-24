class Solution {
public:
int gcd (int a,int b){
    if(a<=1) return 1;
    if(b==0) return a;
    return gcd(b,a%b);
}
    int gcdOfOddEvenSums(int n) {
        int sumeven=n*(n+1);
        int sumodd=n*n;
        return gcd(sumeven,sumodd);
    }
};