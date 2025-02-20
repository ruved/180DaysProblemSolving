class Solution {
public:
    string help(int n,string s,unordered_set<string>&st){
        if(n<0){
            if(st.find(s)==st.end()) return s;
            return "";
        }
        string a=help(n-1,s+"0",st);
        if(a!="") return a;
        return help(n-1,s+"1",st);

    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string>st;
         for(int i=0;i<nums.size();++i) st.insert(nums[i]);
         
        return help(nums.size()-1,"",st);
    }
};