class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int i=0,j=skill.size()-1;
        int prev=skill[i]+skill[j];
        long long ans=0;
        while(i<j){
            if((skill[i]+skill[j])!=prev) return -1;
            ans+=(skill[i]*skill[j]);
            i++;j--;
        }
        return ans;
    }
};