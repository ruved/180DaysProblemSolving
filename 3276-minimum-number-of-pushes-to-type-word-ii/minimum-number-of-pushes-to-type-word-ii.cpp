class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for(int i=0;i<word.length();++i)
            freq[word[i]-'a']++;
        
        sort(freq.begin(),freq.end());
        int i=25;
        int ans=0;
        int count=1;
        while(i>=0){
            for(int j=1;i>=0&&j<=8;++j)
                ans+=count*freq[i--];
            count++;
        }
        return ans;
    }
};