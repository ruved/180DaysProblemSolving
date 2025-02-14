class ProductOfNumbers {
public:
vector<int>arr;
int prod=1;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
       if(num==0){
        arr.resize(0);
        prod=1;
        return ;
       }
       prod=prod*num;
       arr.push_back(prod);
       
    }
    
    int getProduct(int k) {
        if(arr.size()<k) return 0;
        int res=arr[arr.size()-1];
        if(arr.size()==k) return res;
        return res/arr[arr.size()-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */