class ProductOfNumbers {
public:
    vector<int> vec;
    ProductOfNumbers() {}

    void add(int num) { vec.push_back(num); }

    int getProduct(int k) {
        int ans = 1;
        for (int i = vec.size() - k; i < vec.size(); i++)
            ans *= vec[i];
        return ans;
    }
};
