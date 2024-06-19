class Solution {
public:
bool check(vector<int>& bloomDay, int m, int k,int val)
{
    int count=0;
    for(int i=0;i<bloomDay.size()&&m>0;++i)
    {
        if(val>=bloomDay[i])
        {
            count++;
            if(count==k)
            {
                m--;
                count=0;
            }
        }
        else
        {
            count=0;
        }
    }
    if(m!=0) return false;
    return true;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        long c=m;
        c*=k;
        if(c>bloomDay.size()) return -1;
        if(bloomDay.size()==c) return *max_element(bloomDay.begin(),bloomDay.end());

        int l=*min_element(bloomDay.begin(),bloomDay.end());
        int r=*max_element(bloomDay.begin(),bloomDay.end());
        
        int ans=r;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(bloomDay,m,k,mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
            l=mid+1;
        }
        return ans;
    }
};
// [1,_,2,_,3,8,4,7,5,6] m=4 k=2
// 1 0:2 2:3 4:4 6:5 8:6 9:7 7:8 5: