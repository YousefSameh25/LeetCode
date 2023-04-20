class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector < int > frq (2e4 + 10 , 0);
        
        for (int i = 0 ; i < nums.size() ; i++)
            frq[nums[i] + 1e4]++;
        
        vector < vector <int> > v;
        
        for (int i = -1e4 ; i <= 1e4 ; i++)
            v.push_back({frq[i + 1e4] , i});
            
        
        sort(v.begin() , v.end() , greater<>());
        
        vector < int > ans;
        for (int i = 0 ; i < k ; i++)
            ans.push_back(v[i][1]);
        
        return ans;
    }
};