class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        int i=0;
        if(k==1) return r-l+1;
        while(pow(i,k)<l){
            i++;
        }
        int count=0;
        while(pow(i,k)<=r){
            count++;
            i++;
        }
        return count;

    }
};