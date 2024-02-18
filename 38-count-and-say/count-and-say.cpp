class Solution {
public:
    
    string countAndSay(int n) {
        
        if(n==1)
            return "1";
        string res="1";
        
        for(int i=2;i<=n;++i)
        {
            int j=0;
            string temp="";
            while(j<res.length())
            {
                char t=res[j];
                int freq=1;
                j++;
                while(j<res.length()&&t==res[j])
                {
                    freq++;
                    j++;
                }
                cout<<freq<<" "<<t<<"::";
                temp+=to_string(freq)+t;
            }   
            res=temp;
        }
        return res;
    }
};