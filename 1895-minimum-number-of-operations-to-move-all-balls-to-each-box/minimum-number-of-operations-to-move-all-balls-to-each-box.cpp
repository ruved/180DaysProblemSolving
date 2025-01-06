class Solution {
public:
    vector<int> minOperations(string boxes) {

        int l=boxes.length();
        vector<int>right(l,0);
        int count=0;
        if(boxes[l-1]=='1') count++;
        for(int i=l-2;i>=0;--i){
            right[i]+=right[i+1]+count;
            count+=boxes[i]=='1'?1:0;  
        }
        int leftsum=0;
        count=0;
        vector<int>ans(boxes.length(),0);
        for(int i=0;i<l;++i){
            leftsum+=count;
            count+=boxes[i]=='1'?1:0;
            ans[i]=leftsum+right[i];
        }
        return ans;
    }
};