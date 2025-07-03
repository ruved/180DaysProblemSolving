class Solution {
public:
    static char kthCharacter(int k) {
        return (k==1)?'a':1+kthCharacter(k-bit_ceil((unsigned)k)/2);
    }
};