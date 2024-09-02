class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
       int sum=0;
       for(int i=0;i<chalk.size();++i){
            if(sum+chalk[i]<=k)
                sum+=chalk[i];
            else
                return i;
       }
       k%=sum;
       for(int i=0;i<chalk.size();++i){
            if((k-chalk[i])>=0){
                k-=chalk[i];
            }
            else
                return i;
       }
       return 0;
    }
};