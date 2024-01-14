class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector <int> all;
        int i = 0 , j = 0;
        while (i < nums1.size() and j < nums2.size()) {
            if (nums1[i] <= nums2[j])
                all.push_back(nums1[i++]);
            else 
                all.push_back(nums2[j++]);
        }
        while(i < nums1.size())
            all.push_back(nums1[i++]);
        
         while(j < nums2.size())
            all.push_back(nums2[j++]);
        
        return all.size() % 2 ? all[all.size() / 2] : 0.5 * (all[all.size() / 2] + all[all.size() / 2 - 1]);
    }
};