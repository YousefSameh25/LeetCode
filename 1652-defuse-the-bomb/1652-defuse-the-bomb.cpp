class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) 
    {
        int sz = code.size();

        for (int i = 0; i < sz; i++)
            code.push_back(code[i]);

        for (int i = 0; i < sz; i++)
            code.push_back(code[i]);

        vector < int > pre(code.size(), 0);
        int sum = 0;
        for (int i = 0 ; i < code.size(); i++)
            sum += code[i], pre[i] = sum, cout << pre[i] << " ";
        
        int i = sz;

        vector < int > ans(sz, 0);

        for (int j = 0 ; j < sz; j++)
        {
            if (k >= 0)
                ans[j] = pre[i + k] - pre[i];
            else 
                 ans[j] =  pre[i - 1] - pre[i - 1 + k];
            i++;
        }
        return ans;
    }
};