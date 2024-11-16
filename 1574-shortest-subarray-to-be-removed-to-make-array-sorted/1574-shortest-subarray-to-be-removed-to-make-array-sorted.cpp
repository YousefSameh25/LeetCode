class Solution {
public:
    bool remove (int len, vector<int>& arr, vector<bool>& pre_sorted, vector<bool>& suf_sorted)
    {
        if (len == 0)
            return 1;
        len--;
        // Try to remove sub array with len size.
        for (int i = 0 ; i + len < arr.size(); i++)
        {
            bool ok = 1;
            // i -> i + len - 1 will be removed.

            if (i - 1 >= 0)
            {
                ok &= pre_sorted[i - 1];
            }
            if (i + len + 1 < arr.size())
            {
                ok &= suf_sorted[i + len + 1];
            }

            if (i - 1 >= 0 and i + len + 1 < arr.size())
            {
                ok &= arr[i - 1] <= arr[i + len + 1];
            }
            if (ok)
                return ok;
        }
        return 0;
    }
    int findLengthOfShortestSubarray(vector<int>& arr) 
    {
        vector < bool > pre_sorted(arr.size()), suf_sorted(arr.size());
        bool sorted = 1;
        for (int i = 0 ; i < arr.size(); i++)
        {
            if (i)
                sorted &= arr[i] >= arr[i - 1];
            pre_sorted[i] = sorted;    
        }

        sorted = 1;
        for (int i = arr.size() - 1; i >= 0 ; i--)
        {
            if (i != arr.size() - 1)
                sorted &= arr[i] <= arr[i + 1];
            suf_sorted[i] = sorted; 
        }

        int l = 0, r = arr.size() - 1, ans = 0;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if (remove(mid, arr, pre_sorted, suf_sorted))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};