class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int res=0;
        int l=nums1.size();
        int m=nums2.size();
        for(int i=0;i<nums1.size();++i){
            if(m&1) res^=nums1[i]; 
        }
        for(int i=0;i<nums2.size();++i){
            if(l&1) res^=nums2[i]; 
        }
        return res;
    }
};