class Solution {
public:
    string multiply(string num1, string num2) 
    { 
        vector < int > res (401, 0);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for (int i = 0; i < num1.size(); i++)
        {
            for (int j = 0; j < num2.size(); j++)
            {
                int d1 = num1[i]  - '0', d2 = num2[j] - '0';
                int shift = i + j;
                int pro = d1 * d2;
                for (int k = res.size() - 1 - shift ; pro ; k--)
                {
                    int temp = pro % 10;
                    res[k] += temp;
                    
                    int tempK = k;
                    while (res[tempK] > 9)
                    {
                        res[tempK] %= 10;
                        res[--tempK]++;
                    }
                    pro /= 10;
                }
            }
        }
        string ans;
        int i = 0;
        while(i < res.size() and res[i] == 0)
            i++;
        for (;i < res.size(); i++)
            ans.push_back(res[i] + '0');
        if (ans.empty())
            ans = "0";
        return ans; 
    }
};