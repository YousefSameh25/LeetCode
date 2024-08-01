class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for (auto& it : details)
        {
            int age = stoi(it.substr(11, 2));
            ans += age > 60; 
        }
        return ans;
    }
};