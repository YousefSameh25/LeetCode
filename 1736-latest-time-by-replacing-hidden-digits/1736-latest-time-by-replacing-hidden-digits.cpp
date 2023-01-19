class Solution {
public:
    string maximumTime(string time) {
        vector <int> v;
        for (int i = 0 ; i < time.size() ; i++)
        {
            if (time[i] != '?')
                v.push_back(i);
        }
        
        for (int h = 23 ; h >= 0 ; h--)
        {
            for (int m = 59 ; m >= 0 ; m--)
            {
                string H = to_string (h);
                if (H.size() == 1)
                    H = "0" + H;
                string M = to_string (m);
                if (M.size() == 1)
                    M = "0" + M;
                string total = H + ":" + M;
                bool va = 1;
                for (auto idx : v)
                {
                    va &= (time[idx] == total[idx]);
                }
                if (va)
                    return total;
            }
        }
        return "";
    }
};