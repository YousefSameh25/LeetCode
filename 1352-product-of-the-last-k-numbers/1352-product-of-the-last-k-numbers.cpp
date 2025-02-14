class ProductOfNumbers {
private: 
    vector < int > pre;
public:
    ProductOfNumbers() {
        // Nothing
    }
    
    void add(int num) {
        pre.push_back(num);
    }
    
    int getProduct(int k) {
        int ans = 1;
        for (int i = pre.size() - 1; k--; i--)
            ans *= pre[i];
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */