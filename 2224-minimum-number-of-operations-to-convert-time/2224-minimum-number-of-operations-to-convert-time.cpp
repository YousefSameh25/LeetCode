class Solution {
public:
    int convertTime(string current, string correct) 
    {
        int h1 = stoi(current.substr(0 , 2));
        int h2 = stoi(correct.substr(0 , 2));
        int m1 = stoi(current.substr(3 , 2)) + h1 * 60;
        int m2 = stoi(correct.substr(3 , 2)) + h2 * 60;
        int ans = 0;
        m1 = m2 - m1;
        ans += m1 / 60;
        m1 %= 60;
        ans += m1 / 15;
        m1 %= 15;
        ans += m1 / 5;
        m1 %= 5;
        ans += m1 / 1;
        return ans;
    }
};