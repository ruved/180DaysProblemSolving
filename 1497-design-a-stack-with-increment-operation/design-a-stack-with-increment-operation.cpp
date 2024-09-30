class CustomStack {
public:
    vector<int>inc;
     int cap;
     int r;
    CustomStack(int maxSize) {
        cap=maxSize;
        r=0;
    }
    
    void push(int x) {
        if(r<cap){
            inc.push_back(x);
            r++;
        }
    }
    
    int pop() {
        if(r>0){
            int temp=inc[r-1];
            inc.pop_back();
            r--;
            return temp;
        }else
            return -1;

    }
    
    void increment(int k, int val) {
        int i=0;
        while(i<r&&k>0){
            inc[i]=inc[i]+val;
            i++;
            k--;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */