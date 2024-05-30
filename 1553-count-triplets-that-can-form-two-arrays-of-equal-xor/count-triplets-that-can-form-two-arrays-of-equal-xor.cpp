class Solution {
public:
    
    int countTriplets(vector<int>& arr) {
        vector<int>leftxor(arr.size(),0);
        vector<vector<bool>>vis(arr.size(),vector<bool>(arr.size(),false));
        leftxor[0]=arr[0];
        for(int i=1;i<arr.size();++i)
            leftxor[i]=leftxor[i-1]^arr[i];
        int sum=0;
        for(int i=0;i<arr.size();++i){
            for(int k=i+1;k<arr.size();++k){
                for(int j=i+1;j<=k;++j){
                    int a=i>0?leftxor[j-1]^leftxor[i-1]:leftxor[j-1];
                    int b=leftxor[k]^leftxor[j-1];
                    if(a==b) sum++;
                }
            }
        }
        return sum;
        
    }
};