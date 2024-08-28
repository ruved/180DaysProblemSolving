class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();++i)
            mp[arr[i]]=i;
        int res=0;
        int n=arr.size();
        for(int i=0;i<n-2;++i){
            for(int j=i+1;j<n-1;++j){
                int a=arr[i];
                int b=arr[j];
                int count=2;
                while(mp.find(a+b)!=mp.end()){
                    int c=a+b;
                    a=b;
                    b=c;
                    count++;
                }
                res=max(res,count);
            }
        }
        if(res<3) return 0;
        return res;
    }
};