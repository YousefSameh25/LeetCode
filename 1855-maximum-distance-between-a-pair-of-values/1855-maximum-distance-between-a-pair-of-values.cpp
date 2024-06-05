class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        
        
        int n = nums1.size(), m = nums2.size(), mx = 0;
        for (int i = 0 ; i < n ; i++)
        {
            int l = i, r = m - 1, ans = -1;
            while(l <= r)
            {
                int mid = (l + r) >> 1;
                if (nums2[mid] >= nums1[i])
                {
                    l = mid + 1;
                    ans = mid;
                }
                else 
                    r = mid - 1;
            }
            if (ans != -1)
                mx = max(mx , ans - i);
        }
        
        return mx;
    }
};