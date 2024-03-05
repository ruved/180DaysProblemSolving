class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int ans=0;
        set<vector<int>>st;
        for(int i=0;i<nums.size();++i)
        {
            int count=0;
            vector<int>temp;
            for(int j=i;j<nums.size();++j)
            {
                
                if(nums[j]%p==0)
                    count++;
                if(count<=k)
                {
                    temp.push_back(nums[j]);
                    if(st.find(temp)==st.end())
                    {
                        ans++;
                        st.insert(temp);
                    }
                }
                else
                    break;
            }
        }
        return ans;
    }
};