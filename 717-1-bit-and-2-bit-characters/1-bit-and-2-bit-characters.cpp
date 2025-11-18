class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        
        int l=bits.size()-1;
        int i=0;
        
        while(i<l)
        {
            if(bits[i]==1)
                i+=2;
            else
                i++;
        }
        return i==l;
        
    }
};