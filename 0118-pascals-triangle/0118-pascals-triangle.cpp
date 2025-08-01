class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector <vector < int >> ret;
        for (int i = 1 ; i <= numRows ; i++)
        {
            vector < int > t ;
            for (int j = 1 ; j <= i ; j++)
            {
                if (j == 1 or j == i)
                    t.push_back(1);
                else
                    t.push_back(ret [i - 2][j - 2] + ret [i - 2][j - 1]);
            }
            ret.push_back(t);
        }
        return ret;
    }
};