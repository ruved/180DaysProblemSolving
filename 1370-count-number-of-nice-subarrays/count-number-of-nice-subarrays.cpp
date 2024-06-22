class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count=0;
        int ans=0;
        int j=0;
        for(int i=0;i<nums.size();++i){

            if(nums[i]%2==1) count++;
            cout<<count<<" ";
            if(count==k){
                int temp=0;
                while(j<=i&&count==k){
                    temp++;
                    if(nums[j]%2==1) count--;
                    j++;
                }
                int k=i+1;
                ans+=temp;
                while(k<nums.size()&&nums[k]%2==0){
                    k++;
                    ans+=temp;
                }  
            }
            
        }
        return ans;
    }
};