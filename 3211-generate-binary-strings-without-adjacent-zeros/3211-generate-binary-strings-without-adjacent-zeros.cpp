class Solution 
{
public:
    vector<string> validStrings(int n) 
    {
        vector < string > ans;
        for (int msk = 0; msk < (1 << n); msk++)
        {
            string temp;
            for (int i = 0 ; i < n; i++)
            {
                if ((msk >> i) & 1)
                    temp.push_back('1');
                else
                {
                    if (temp.size() and temp.back() == '0')
                        break;
                    temp.push_back('0');
                }
            }
            if (temp.size() == n)
                ans.push_back(temp);
        }
        return ans;
    }
};