class ProductOfNumbers {
public:
vector<int>arr;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
       arr.push_back(1);
       for(int i=arr.size()-1;i>=0;--i){
            arr[i]*=num;
       } 
    }
    
    int getProduct(int k) {
        int i=arr.size()-1;
        return arr[i-k+1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */