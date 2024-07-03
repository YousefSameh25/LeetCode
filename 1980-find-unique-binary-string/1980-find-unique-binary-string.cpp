class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        
        unordered_map <string , bool> mp;
        
        for (auto it : nums)
            mp[it] = 1;
        
        
        for (int i = 0; i < (1 << nums[0].size()); i++)
        {
            string str;
            for (int b = 0; b < nums[0].size(); b++)
                (i & (1 << b))? str.push_back('1') : str.push_back('0');
            if (!mp.count(str))
                return str;
        }
        return "";
        
    }
};