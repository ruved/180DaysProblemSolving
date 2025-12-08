class Solution {
public:
    int countTriples(int n) {
        int cnt=0;
        for(int i=3;i<=n;++i){
            for(int j=2;j<i;++j)
                for(int k=1;k<j;++k){
                    if((i*i)==(j*j+k*k)) cnt+=2;
                }
        }
        return cnt;
    }
};