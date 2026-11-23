class ProductOfNumbers {
public:
    vector<int> p;
    int size = 0;
    
    ProductOfNumbers() {
        p.push_back(1);
        size = 0;
    }
    
    void add(int num) {
        if(num == 0){
            p = {1};
            size = 0;
        } else {
            p.push_back(p[size] * num);
            size++;
        }
    }
    
    int getProduct(int k) {
        if(k > size) return 0;
        return p[size] / p[size - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */