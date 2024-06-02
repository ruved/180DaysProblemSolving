class Solution {
public:
    int countCollisions(string directions) {
        // 1. when both car moving in opposite direction 
        // 2. when sttion car present in the way of moving SL, RS
        // 3. when both car is Stantion SS it will not impact
        //RRRSSLRR
        int last=0;//2 1 station 2 right, 0 left
        int countcollioson=0;
       stack<char>st;
       for(int i=0;i<directions.length();++i){
        if(directions[i]=='L'){
            if(!st.empty()){
                if(st.top()=='S'){ 
                    countcollioson++;
                    st.push('S');  
                }
                else if(st.top()=='R'){
                    st.pop();
                    countcollioson+=2;
                    while(!st.empty()&&st.top()=='R'){
                        countcollioson++;
                        st.pop();
                    }
                    st.push('S');  
                }
                
            }    
        }
        else{
            if(directions[i]=='S')
                while(!st.empty()&&st.top()=='R'){
                    countcollioson++;
                    st.pop();
                }
            st.push(directions[i]);
        }
        // cout<<countcollioson<<" ";
       }
        return countcollioson; 
    }
  
};