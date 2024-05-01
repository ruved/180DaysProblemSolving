class Solution {
public:
    string reversePrefix(string word, char ch) {
        for(int i=0;i<word.length();++i)
        {
            if(word[i]==ch)
            {
                int k=0;
                while(k<i)
                {
                    char temp=word[k];
                    word[k++]=word[i];
                    word[i--]=temp;
                }
                return word;
            }
        }
        return word;
    }
};