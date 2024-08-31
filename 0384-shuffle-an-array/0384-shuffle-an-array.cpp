class Solution {
private:
    vector <int> originalNum, tempNum;
public:
    Solution(vector<int>& nums) {
        originalNum = nums;
        tempNum = nums;
    }
    
    vector<int> reset() {
        tempNum = originalNum;
        return tempNum;
    }
    
    vector<int> shuffle() 
    {
        for (int i = 0 ; i < tempNum.size(); i++)
        {
            swap(tempNum[i], tempNum[rand() % tempNum.size()]);
        }
        return tempNum;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */