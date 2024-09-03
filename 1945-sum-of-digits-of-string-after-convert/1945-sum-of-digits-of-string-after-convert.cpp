class Solution {
public:
    int getLucky(string s, int k) {
        string str;
        for (auto it : s)
            str += to_string((it - 'a') + 1);

        int ans = 0;
        while(k--)
        {
            int temp = 0;
            for (auto it: str)
                temp += it - '0';
            ans = temp;
            str = to_string(temp); 
        } 
        return ans;
    }
};