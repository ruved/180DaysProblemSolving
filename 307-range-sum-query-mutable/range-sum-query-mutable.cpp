class NumArray {
public:
vector<int>segTree;
vector<int>num;
    NumArray(vector<int>& nums) {
        int n=nums.size();
        num=nums;
        vector<int>tree(2*n,0);
        segTree=tree;
        for(int i=0;i<n;++i)
            segTree[i+n]=nums[i];
        for(int i=n-1;i>0;--i)
            segTree[i]=segTree[i<<1]+segTree[i<<1|1];

    }
    
    void update(int index, int val) {
        num[index]=val;
        int n=num.size();
        segTree[n+index]=val;

        for (int i=index+n; i > 1; i >>= 1) 
            segTree[i>>1] = segTree[i]+segTree[i^1]; 
    }
    
    int sumRange(int left, int right) {
        int res=0;
        int n=num.size();
        for (int l=n+left,r=n+right+1; l<r; l>>= 1,r >>= 1) {
            if (l&1)  
            res+=segTree[l++]; 
      
            if (r&1)  
                res+=segTree[--r];
        }
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */