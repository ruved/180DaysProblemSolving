class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>ans(A.size(),0);
        unordered_set<int> st1;
        unordered_set<int> st2;

        for(int i=0;i<A.size();++i){
            if(st1.find(B[i])!=st1.end()){
                ans[i]++;
            }
            st2.insert(B[i]);
            if(st2.find(A[i])!=st2.end()){
                ans[i]++;
            }
            if(i>0)
                ans[i]+=ans[i-1];
            st1.insert(A[i]);
        }
    return ans;
    }
};