class Solution {
public:
void help(int &n,int i,int &k,string temp,string &res){
    if(n==i){
        k--;
        if(k==0) {res=temp;return;}
        return;
    }
    if(i==0)
    {
        help(n,i+1,k,temp+"a",res);
        help(n,i+1,k,temp+"b",res);
        help(n,i+1,k,temp+"c",res);
    }else{
        if(temp[i-1]=='a'){
            help(n,i+1,k,temp+"b",res);
            help(n,i+1,k,temp+"c",res);
        }else if(temp[i-1]=='b'){
            help(n,i+1,k,temp+"a",res);
            help(n,i+1,k,temp+"c",res);
        }else {
             help(n,i+1,k,temp+"a",res);
            help(n,i+1,k,temp+"b",res);
        }
    }
}
    string getHappyString(int n, int k) {
        string res;
        help(n,0,k,"",res);
        return res;
    }
};