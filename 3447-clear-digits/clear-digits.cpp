class Solution {
public:
    string clearDigits(string s) {
        stack<int>stk;
    priority_queue<int>pq;

        for(int i=0;i<s.length();++i)
        {
            if(isdigit(s[i])) stk.push(i);
            else
            pq.push(i);
        }
        string ans="";
        while(!stk.empty()){
            int j=stk.top();
            while(pq.top()>j){
            ans=s[pq.top()]+ans;
            pq.pop();
            }
            if(!pq.empty()) pq.pop();
            stk.pop();
        }
        while(!pq.empty()){
            ans=s[pq.top()]+ans;
            pq.pop();
        }
        
        return ans;
    }
};