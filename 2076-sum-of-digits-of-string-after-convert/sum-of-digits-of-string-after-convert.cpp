class Solution {
public:
    int getLucky(string s, int k) {
        string encodedString="";
        for(int i=0;i<s.length();++i)
         encodedString+=to_string(s[i]-'a'+1);

        int sum=0;
        while(k--){
            sum=0;
            for(int i=0;i<encodedString.length();++i)
                sum+=encodedString[i]-'0';
            encodedString=to_string(sum);
        }
        return sum;      
    }
};