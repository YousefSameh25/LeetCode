class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map <char , int> weight;
        
        for (int i = 0 ; i < order.size(); i++)
            weight[order[i]] = i;
        
        sort(s.begin(), s.end(), [&](char a, char b) -> bool 
        {
            return weight[a] < weight[b];
        });
        
        return s;
    }
};