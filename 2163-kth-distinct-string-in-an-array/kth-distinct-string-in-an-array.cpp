class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>st1;
        
        for(int i=0;i<arr.size();++i){
            if(st1.find(arr[i])==st1.end())
                st1[arr[i]]=i;
            else
                st1[arr[i]]=-1;
        }
        
        for(string it:arr){
            if(st1[it]!=-1){
                k--;
                if(k==0)
                return it;
            }
        }
        
      return "";
    }
};