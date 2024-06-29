class Solution {
public:
    void sortColors(vector<int>& nums) {
        int frq[3] = {0, 0, 0};
        for (auto it : nums)
            frq[it]++;
        
        nums.clear();
        
        for (int i = 0 ; i < 3 ; i++)
            while(frq[i]--)
                nums.push_back(i);
    }
};