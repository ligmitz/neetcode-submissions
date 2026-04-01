class KthLargest {
    int kth;
    multiset<int, greater<int>> mult;
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for (int num:nums) mult.insert(num);
    }
    
    int add(int val) {
        mult.insert(val);
        return *next(mult.begin(), kth - 1);
    }
};
