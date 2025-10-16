class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int>freq(value,0);
        for(int i=0;i<nums.size();++i){
            int temp=abs(nums[i])%value;
            if(nums[i]<0)   
                temp=(value-temp)%value;
            // cout<<temp<<" ";
            freq[temp]++;
        }

        int ans=INT_MAX,resval=0;
        for(int i=0;i<value;++i){
            if(freq[i]==0) return i;
            if(freq[i]<ans){      
                ans=freq[i];
                resval=i;
            }
        }
        return ans*value+resval;
    }
};