class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int mx = 0;
        for (int i = 0 ; i < arr.size() ; i++)
        {
            int l = 0;
            for (int j = i - 1 ; j >= 0 ; j--){
                if (arr[j] >= arr[j + 1])
                    break;
                l++;
            }
            int r = 0;
            for (int j = i + 1 ; j < arr.size() ; j++){
                if (arr[j] >= arr[j - 1])
                    break;
                r++;
            }
            if (l == 0 || r == 0)
                continue;
            mx = max(mx , r + l + 1);
        }
        return mx;
    }
};