class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) 
    {
        int n = box.size(), m = box.back().size();
        for (int i = 0 ; i < n; i++)
        {
            for ( int j = m - 1; j >= 0; j--)
            {
                if (box[i][j] != '#')
                    continue;
                int pos = j;
                while(pos + 1 < m and box[i][pos + 1] == '.')
                    swap(box[i][pos], box[i][pos + 1]), pos++;
            }
        }
        vector < vector < char >> ans (m, vector < char > (n));
        int ii = 0, jj = n - 1;
        for ( int i = 0  ; i < n ; i++)
        {
            for ( int j = 0 ; j < m; j++)
            {
                ans[ii][jj] = box[i][j];
                ii++;
            }
            jj--, ii = 0;
        } 
        return ans;
    }
};