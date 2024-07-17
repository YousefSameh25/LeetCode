class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int TotalApples = 0;
        for (auto it : apple)
            TotalApples += it;
        sort(capacity.rbegin(), capacity.rend());
        for (int i = 0 ; i < capacity.size(); i++)
        {
            if (capacity[i] >= TotalApples)
                return i + 1;
            TotalApples -= capacity[i];
        }
        return -111111;
    }
};