class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0;
        int j=0;
        long long count1=0;
        long long count2=0;
        while(i<version1.length()||j<version2.length())
        {
             count1=0;
            while(i<version1.length()&&version1[i]!='.')
            {
                count1=count1*10+version1[i]-'0';
                i++;
            }
            count2=0;
            while(j<version2.length()&&version2[j]!='.')
            {
                count2=count2*10+version2[j]-'0';
                j++;
            }
            if(count1<count2) return -1;
            if(count1>count2) return 1;
            i++;
            j++;
        }
         return 0;
    }
};