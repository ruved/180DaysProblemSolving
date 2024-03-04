class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i=0,j=tokens.size()-1;
        int score=0,count=0;
        while(i<=j)
        {
            if(power>=tokens[i])
            {
                count++;
                power-=tokens[i];
                i++;
            }
            else if(power<tokens[i])
            {
                if(count>=1)
                {
                    count--;
                    power+=tokens[j];
                    j--;
                }
                else
                   break;
            }
            score=max(score,count);
        }
        return score;
    }
};