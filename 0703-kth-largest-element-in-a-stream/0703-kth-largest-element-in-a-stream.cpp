#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> 

class KthLargest {
public:
    ordered_set ost;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (auto it : nums)
            ost.insert(it);
    }
    
    int add(int val) {
        ost.insert(val);
        for (auto it : ost)
            cout << it << " ";
            cout << endl;
        return *ost.find_by_order(ost.size() - K);
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */