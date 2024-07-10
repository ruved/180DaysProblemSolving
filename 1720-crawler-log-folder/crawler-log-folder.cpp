class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth =0;
        for(int i=0;i<logs.size();++i){
            if(logs[i][0]=='.'){
                if(logs[i][1]=='.'&&logs[i][2]=='/')
                    depth=max(0,depth-1); 
            }
            else
                depth++;
        }
        return depth;
    }
};