class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ans=0;
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        for(int i=0;i<nums1.size();++i){
            for(int j=0;j<nums1.size();++j)
                mp1[nums1[i] + nums2[j] ]++;
        }

        for(int i=0;i<nums1.size();++i){
            for(int j=0;j<nums1.size();++j)
                mp2[nums3[i] + nums4[j] ]++;
        }
        for( auto it: mp1)
        {
            if(mp2.find(-it.first)!=mp2.end())
            ans+=it.second*mp2[-it.first];
        }

        return ans;
    }
};
//0
//nums1 ko map main dal do mp1
//nums2 ko map main dal do mp2
//nums3 ko map main dal do mp3
//0-nums4[i]