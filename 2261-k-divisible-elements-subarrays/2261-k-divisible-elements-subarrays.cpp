class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set < vector < int > > st;
        for (int i = 0 ; i < nums.size(); i++)
        {
            vector < int > temp;
            int cnt = 0;
            for (int j = i ; j < nums.size(); j++)
            {
                cnt += (nums[j] % p == 0);
                if (cnt > k)
                    break;
                temp.push_back(nums[j]);
                st.insert(temp);
            }
        }
        return st.size();
    }
};