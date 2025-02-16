class ProductOfNumbers {
public:
    vector<int> A = {1};
    ProductOfNumbers() {
        
    }
    
    void add(int a) {
        if(a) A.push_back(A.back()*a);
        else A = {1};
    }
    
    int getProduct(int k) {
        if(k >= A.size()) return 0;
        return A.back()/A[A.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */