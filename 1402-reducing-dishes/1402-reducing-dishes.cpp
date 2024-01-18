class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
            
        sort(satisfaction.begin() , satisfaction.end() , greater<int>());
        
        long long pre = 0 , sum = 0, mx = 0;
        
        for (int i = 0 ; i < satisfaction.size() ; i++)
        {
            pre += satisfaction[i];
            long long tmp = pre + sum;
            sum = tmp;
            mx = max(mx , sum);
        }
        return mx;
    }
};