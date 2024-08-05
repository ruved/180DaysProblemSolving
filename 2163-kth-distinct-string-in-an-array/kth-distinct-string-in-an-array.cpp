class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>st1;
        map<int,string>st2;
        
        for(int i=0;i<arr.size();++i){
            if(st1.find(arr[i])==st1.end())
                st1[arr[i]]=i;
            else
                st1[arr[i]]=-1;
        }
        
        for(auto it:st1)
            if(it.second!=-1)
                st2[it.second]=it.first;

        
      for(auto it:st2){
        if(k==1)
        return it.second;
        k--;
      }
      return "";
    }
};