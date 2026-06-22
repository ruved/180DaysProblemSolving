class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        unsigned int cnt=0;
        for(int i=0;i<nums.size();++i)
        {
            long unsigned int sum=0;
            for(int j=i;j<nums.size();++j){
                sum+=nums[j];
                // cout<<i<<" "<<j<<" "<<sum<<" - ";
                long unsigned int d=sum;
                bool t1=false,t2=false;
                t1=d%10==x;
                while(d>=10){
                    d/=10;
                }
                t2=d==x;
                 if(t1&&t2) cnt++;   
            }
        }
        return cnt;
    }
};