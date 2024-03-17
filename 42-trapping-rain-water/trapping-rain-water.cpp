class Solution {
public:
    int trap(vector<int>& height) {
    int l=0,r=height.size()-1;
    int lmax=0,rmax=0,water=0;
    while(l<r)
    {
        if(height[l]<height[r])
        {
            if(height[l]>lmax)
                lmax=height[l];
            water+=lmax-height[l];
            l++;
        }
        else
        {
            if(height[r]>rmax)
                rmax=height[r];
            water+=rmax-height[r];
            r--;
        }
    }
        return water;
        
    }
};