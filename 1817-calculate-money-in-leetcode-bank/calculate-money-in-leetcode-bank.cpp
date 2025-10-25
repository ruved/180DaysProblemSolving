class Solution {
public:
    int totalMoney(int n) {
        int x=n/7;
        int d=n%7;
        int res=(7*x*(7+x))/2;
        int rem=(x*d)+(d*(d+1))/2;
        return res+rem;
        
    }
};