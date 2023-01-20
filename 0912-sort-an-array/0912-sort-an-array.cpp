class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        unordered_map <int , int> frq;
        for (auto it : nums)
            frq[it] ++;
        vector <int> ans;
        for(int i = -5e4 ; i <= 5e4 ; i++)
        {
            if (not frq.count(i))
                continue;
            int f = frq[i];
            while(f--)
                ans.push_back(i);
        }
        return ans;
    }
};